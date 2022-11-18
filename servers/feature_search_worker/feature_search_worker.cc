#include "feature_search_worker.h"

#include "Poco/Format.h"
#include "Poco/Timestamp.h"
#include "api/common.pb.h"
#include "api/feature_search_inner.grpc.pb.h"
#include "api/feature_search_inner.pb.h"
#include "config.h"
#include "donde/definitions.h"
#include "donde/feature_search/api.h"
#include "donde/utils.h"
#include "nlohmann/json.hpp"
#include "source/feature_search/search_worker/brute_force_searcher.h"
#include "source/feature_search/simple_driver.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

#include <algorithm>
#include <cassert>
#include <grpc/grpc.h>
#include <grpc/impl/codegen/status.h>
#include <grpcpp/security/server_credentials.h>
#include <grpcpp/server.h>
#include <grpcpp/server_builder.h>
#include <grpcpp/server_context.h>
#include <grpcpp/support/status.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <opencv2/core/hal/interface.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

using com::sekirocc::feature_search::inner::BatchAddFeaturesRequest;

using com::sekirocc::feature_search::inner::BatchAddFeaturesResponse;
using com::sekirocc::feature_search::inner::BatchDeleteFeaturesRequest;
using com::sekirocc::feature_search::inner::BatchDeleteFeaturesResponse;
using com::sekirocc::feature_search::inner::SearchFeatureRequest;
using com::sekirocc::feature_search::inner::SearchFeatureResponse;
using com::sekirocc::feature_search::inner::TrainIndexRequest;
using com::sekirocc::feature_search::inner::TrainIndexResponse;

using com::sekirocc::common::FaceFeature;

using com::sekirocc::common::ResultCode;

using donde::feature_search::DBShard;

using grpc::ServerContext;
using grpc::Status;

using json = nlohmann::json;

FeatureSearchWorkerImpl::FeatureSearchWorkerImpl(Config& server_config) : config(server_config) {
    driver = std::make_shared<donde::feature_search::SimpleDriver>(
        server_config.get_searcher_config()["filepath"]);
    // searcher = std::make_shared<search::BruteForceSearcher>(*driver);
};

FeatureSearchWorkerImpl::~FeatureSearchWorkerImpl(){};

void FeatureSearchWorkerImpl::Start() { searcher->Start(); };

void FeatureSearchWorkerImpl::Stop() { searcher->Stop(); };

Status FeatureSearchWorkerImpl::ServeDBShards(ServerContext* context,
                                              const ServeDBShardsRequest* request,
                                              ServeDBShardsResponse* response) {
    std::vector<DBShard> shard_infos;
    for (auto& s : request->shards()) {
        shard_infos.push_back(DBShard{
            .db_id = s.db_id(),
            .shard_id = s.shard_id(),
            .capacity = 0,
            .used = 0,
            .is_closed = false,
        });
    };
    searcher->ServeShards(shard_infos);
    return Status::OK;
};

Status FeatureSearchWorkerImpl::CloseDBShards(ServerContext* context,
                                              const CloseDBShardsRequest* request,
                                              CloseDBShardsResponse* response) {
    std::vector<DBShard> shard_infos;
    for (auto& s : request->shards()) {
        shard_infos.push_back(DBShard{
            .db_id = s.db_id(),
            .shard_id = s.shard_id(),
            .capacity = 0,
            .used = 0,
            .is_closed = false,
        });
    };
    searcher->CloseShards(shard_infos);
    return Status::OK;
};

Status FeatureSearchWorkerImpl::GetSystemInfo(ServerContext* context,
                                              const GetSystemInfoRequest* request,
                                              GetSystemInfoResponse* response) {
    return Status::OK;
};

Status FeatureSearchWorkerImpl::TrainIndex(ServerContext* context, const TrainIndexRequest* request,
                                           TrainIndexResponse* response) {
    searcher->TrainIndex();
    return Status::OK;
};

Status FeatureSearchWorkerImpl::BatchAddFeatures(ServerContext* context,
                                                 const BatchAddFeaturesRequest* request,
                                                 BatchAddFeaturesResponse* response) {
    auto items = request->feature_items();
    auto db_id = request->db_id();

    std::vector<donde::feature_search::FeatureDbItem> fts;

    for (auto& item : items) {
        auto ft = item.feature();
        // auto meta = ((AddFeatureRequest*)request)->mutable_meta();
        // (*meta)["a"] = "b";
        donde::Feature feature(donde::convertFeatureBlobToFloats(ft.blob()),
                               std::string(ft.model()), ft.version());
        std::map<string, string> meta = donde::convertMetadataToMap(item.meta());
        fts.push_back(donde::feature_search::FeatureDbItem{
            .feature = feature,
            .metadata = meta,
        });
    }

    std::vector<std::string> feature_ids = searcher->AddFeatures(db_id, fts);

    for (auto& id : feature_ids) {
        response->add_feature_ids(id);
    }
    // another approach:
    // response->mutable_feature_ids()->Add(feature_ids.begin(), feature_ids.end());
    response->set_code(ResultCode::OK);

    return Status::OK;
};

Status FeatureSearchWorkerImpl::BatchDeleteFeatures(ServerContext* context,
                                                    const BatchDeleteFeaturesRequest* request,
                                                    BatchDeleteFeaturesResponse* response) {

    auto ids = request->feature_ids();
    auto db_id = request->db_id();
    // construct from iterator
    const std::vector<std::string> feature_ids{ids.begin(), ids.end()};
    searcher->RemoveFeatures(db_id, feature_ids);

    return Status::OK;
};

Status FeatureSearchWorkerImpl::SearchFeature(ServerContext* context,
                                              const SearchFeatureRequest* request,
                                              SearchFeatureResponse* response) {
    auto db_ids = request->db_ids();

    auto ft = request->query();
    auto topk = request->topk();
    donde::Feature query(donde::convertFeatureBlobToFloats(ft.blob()), std::string(ft.model()),
                         ft.version());

    // FIXME: only search first db now!!!
    std::vector<donde::feature_search::FeatureSearchItem> ret
        = searcher->SearchFeature(db_ids.Get(0), query, topk);

    for (const auto& feature_search_result : ret) {
        auto item = response->add_items();
        item->set_score(feature_search_result.score);

        // convert ft => face_feat.
        auto ft = feature_search_result.target;
        FaceFeature* face_feat = item->mutable_feature();

        const char* p = reinterpret_cast<const char*>(&ft.raw[0]);
        size_t size = sizeof(float) * ft.raw.size();

        std::string str;
        str.resize(size);
        std::copy(p, p + size, str.data());

        face_feat->set_blob(str);
        face_feat->set_version(ft.version);
        face_feat->set_model(ft.model);
    }

    response->set_code(ResultCode::OK);

    return Status::OK;
};
