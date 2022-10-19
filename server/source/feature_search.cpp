#include "feature_search.h"

#include "Poco/Format.h"
#include "Poco/Timestamp.h"
#include "concurrent_processor.h"
#include "config.h"
#include "face_pipeline.h"
#include "gen/pb-cpp/server.grpc.pb.h"
#include "gen/pb-cpp/server.pb.h"
#include "nlohmann/json.hpp"
#include "search/searcher.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "types.h"
#include "utils.h"

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

using com::sekirocc::face_service::AddFeatureRequest;
using com::sekirocc::face_service::AddFeatureResponse;
using com::sekirocc::face_service::DeleteFeatureRequest;
using com::sekirocc::face_service::DeleteFeatureResponse;
using com::sekirocc::face_service::SearchFeatureRequest;
using com::sekirocc::face_service::SearchFeatureResponse;
using com::sekirocc::face_service::TrainIndexRequest;
using com::sekirocc::face_service::TrainIndexResponse;

using com::sekirocc::face_service::ResultCode;


using grpc::ServerContext;
using grpc::Status;

using json = nlohmann::json;

FeatureSearchImpl::FeatureSearchImpl(Config& server_config)
    : config(server_config), searcher(new search::Searcher(server_config.get_searcher_config())){};

FeatureSearchImpl::~FeatureSearchImpl(){};

void FeatureSearchImpl::Start() { searcher->Init(); };

void FeatureSearchImpl::Stop() { searcher->Terminate(); };

Status FeatureSearchImpl::TrainIndex(ServerContext* context, const TrainIndexRequest* request,
                                     TrainIndexResponse* response) {
    return Status::OK;
};

Status FeatureSearchImpl::AddFeature(ServerContext* context, const AddFeatureRequest* request,
                                     AddFeatureResponse* response) {
    auto ft = request->feature();
    Feature feature(convertFeatureBlobToFloats(ft.blob()), std::string(ft.model()), ft.version());

    std::vector<Feature> fts{feature};
    std::vector<uint64> ids;
    ids.reserve(fts.size());

    std::vector<std::string> feature_ids = searcher->AddFeatures(fts);

    response->set_code(ResultCode::OK);
    return Status::OK;
};

Status FeatureSearchImpl::DeleteFeature(ServerContext* context, const DeleteFeatureRequest* request,
                                        DeleteFeatureResponse* response) {
    return Status::OK;
};

Status FeatureSearchImpl::SearchFeature(ServerContext* context, const SearchFeatureRequest* request,
                                        SearchFeatureResponse* response) {
    return Status::OK;
};