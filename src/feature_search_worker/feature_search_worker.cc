#include "feature_search_worker.h"

#include "Poco/Format.h"
#include "Poco/Timestamp.h"
#include "common.pb.h"
#include "config.h"
#include "donde/definitions.h"
#include "donde/feature_search/search_worker/brute_force_worker.h"
#include "donde/feature_search/search_worker/db_search_worker.h"
#include "donde/feature_search/simple_driver.h"
#include "donde/utils.h"
#include "feature_search_inner.grpc.pb.h"
#include "feature_search_inner.pb.h"
#include "nlohmann/json.hpp"
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

using donde_toolkits::feature_search::DBShard;
using donde_toolkits::feature_search::search_worker::BruteForceWorker;

using grpc::ServerContext;
using grpc::Status;

using json = nlohmann::json;

FeatureSearchWorkerImpl::FeatureSearchWorkerImpl(Config& server_config) : config(server_config) {
    driver = std::make_shared<donde_toolkits::feature_search::SimpleDriver>(
        server_config.get_searcher_config()["filepath"]);
    worker = std::make_shared<BruteForceWorker>(*driver);
};

FeatureSearchWorkerImpl::~FeatureSearchWorkerImpl(){};

void FeatureSearchWorkerImpl::Start() { worker->Start(); };

void FeatureSearchWorkerImpl::Stop() { worker->Stop(); };

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
    worker->ServeShards(shard_infos);
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
    worker->CloseShards(shard_infos);
    return Status::OK;
};

Status FeatureSearchWorkerImpl::GetSystemInfo(ServerContext* context,
                                              const GetSystemInfoRequest* request,
                                              GetSystemInfoResponse* response) {
    return Status::OK;
};

Status FeatureSearchWorkerImpl::TrainIndex(ServerContext* context, const TrainIndexRequest* request,
                                           TrainIndexResponse* response) {
    worker->TrainIndex();
    return Status::OK;
};

Status FeatureSearchWorkerImpl::BatchAddFeatures(ServerContext* context,
                                                 const BatchAddFeaturesRequest* request,
                                                 BatchAddFeaturesResponse* response) {
    auto items = request->feature_items();
    auto db_id = request->db_id();

    std::vector<donde_toolkits::feature_search::FeatureDbItem> fts;

    for (auto& item : items) {
        auto ft = item.feature();
        // auto meta = ((AddFeatureRequest*)request)->mutable_meta();
        // (*meta)["a"] = "b";
        donde_toolkits::Feature feature(donde_toolkits::convertFeatureBlobToFloats(ft.blob()),
                                        std::string(ft.model()), ft.version());
        // TODO
        std::map<string, string> meta = {}; // donde_toolkits::convertMetadataToMap(item.meta());
        fts.push_back(donde_toolkits::feature_search::FeatureDbItem{
            .feature = feature,
            .metadata = meta,
        });
    }

    std::vector<std::string> feature_ids = worker->AddFeatures(db_id, fts);

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
    worker->RemoveFeatures(db_id, feature_ids);

    return Status::OK;
};

Status FeatureSearchWorkerImpl::SearchFeature(ServerContext* context,
                                              const SearchFeatureRequest* request,
                                              SearchFeatureResponse* response) {
    auto db_ids = request->db_ids();

    auto ft = request->query();
    auto topk = request->topk();
    donde_toolkits::Feature query(donde_toolkits::convertFeatureBlobToFloats(ft.blob()),
                                  std::string(ft.model()), ft.version());

    // FIXME: only search first db now!!!
    std::vector<donde_toolkits::feature_search::FeatureSearchItem> ret
        = worker->SearchFeature(db_ids.Get(0), query, topk);

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
