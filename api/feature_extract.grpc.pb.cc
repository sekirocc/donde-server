// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: feature_extract.proto

#include "feature_extract.pb.h"
#include "feature_extract.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace com {
namespace sekirocc {
namespace feature_extract {

static const char* FaceService_method_names[] = {
  "/com.sekirocc.feature_extract.FaceService/Detect",
  "/com.sekirocc.feature_extract.FaceService/ExtractFeature",
  "/com.sekirocc.feature_extract.FaceService/CompareFeature",
};

std::unique_ptr< FaceService::Stub> FaceService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< FaceService::Stub> stub(new FaceService::Stub(channel, options));
  return stub;
}

FaceService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_Detect_(FaceService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_ExtractFeature_(FaceService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_CompareFeature_(FaceService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status FaceService::Stub::Detect(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::DetectionRequest& request, ::com::sekirocc::feature_extract::DetectionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::com::sekirocc::feature_extract::DetectionRequest, ::com::sekirocc::feature_extract::DetectionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Detect_, context, request, response);
}

void FaceService::Stub::async::Detect(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::DetectionRequest* request, ::com::sekirocc::feature_extract::DetectionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::com::sekirocc::feature_extract::DetectionRequest, ::com::sekirocc::feature_extract::DetectionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Detect_, context, request, response, std::move(f));
}

void FaceService::Stub::async::Detect(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::DetectionRequest* request, ::com::sekirocc::feature_extract::DetectionResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Detect_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::feature_extract::DetectionResponse>* FaceService::Stub::PrepareAsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::com::sekirocc::feature_extract::DetectionResponse, ::com::sekirocc::feature_extract::DetectionRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Detect_, context, request);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::feature_extract::DetectionResponse>* FaceService::Stub::AsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDetectRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FaceService::Stub::ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::ExtractionRequest& request, ::com::sekirocc::feature_extract::ExtractionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::com::sekirocc::feature_extract::ExtractionRequest, ::com::sekirocc::feature_extract::ExtractionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ExtractFeature_, context, request, response);
}

void FaceService::Stub::async::ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::ExtractionRequest* request, ::com::sekirocc::feature_extract::ExtractionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::com::sekirocc::feature_extract::ExtractionRequest, ::com::sekirocc::feature_extract::ExtractionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ExtractFeature_, context, request, response, std::move(f));
}

void FaceService::Stub::async::ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::ExtractionRequest* request, ::com::sekirocc::feature_extract::ExtractionResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ExtractFeature_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::feature_extract::ExtractionResponse>* FaceService::Stub::PrepareAsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::com::sekirocc::feature_extract::ExtractionResponse, ::com::sekirocc::feature_extract::ExtractionRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ExtractFeature_, context, request);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::feature_extract::ExtractionResponse>* FaceService::Stub::AsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncExtractFeatureRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FaceService::Stub::CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::CompareRequest& request, ::com::sekirocc::feature_extract::CompareResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::com::sekirocc::feature_extract::CompareRequest, ::com::sekirocc::feature_extract::CompareResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CompareFeature_, context, request, response);
}

void FaceService::Stub::async::CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::CompareRequest* request, ::com::sekirocc::feature_extract::CompareResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::com::sekirocc::feature_extract::CompareRequest, ::com::sekirocc::feature_extract::CompareResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompareFeature_, context, request, response, std::move(f));
}

void FaceService::Stub::async::CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::CompareRequest* request, ::com::sekirocc::feature_extract::CompareResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompareFeature_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::feature_extract::CompareResponse>* FaceService::Stub::PrepareAsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::CompareRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::com::sekirocc::feature_extract::CompareResponse, ::com::sekirocc::feature_extract::CompareRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CompareFeature_, context, request);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::feature_extract::CompareResponse>* FaceService::Stub::AsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::feature_extract::CompareRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCompareFeatureRaw(context, request, cq);
  result->StartCall();
  return result;
}

FaceService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FaceService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FaceService::Service, ::com::sekirocc::feature_extract::DetectionRequest, ::com::sekirocc::feature_extract::DetectionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FaceService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::com::sekirocc::feature_extract::DetectionRequest* req,
             ::com::sekirocc::feature_extract::DetectionResponse* resp) {
               return service->Detect(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FaceService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FaceService::Service, ::com::sekirocc::feature_extract::ExtractionRequest, ::com::sekirocc::feature_extract::ExtractionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FaceService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::com::sekirocc::feature_extract::ExtractionRequest* req,
             ::com::sekirocc::feature_extract::ExtractionResponse* resp) {
               return service->ExtractFeature(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FaceService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FaceService::Service, ::com::sekirocc::feature_extract::CompareRequest, ::com::sekirocc::feature_extract::CompareResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FaceService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::com::sekirocc::feature_extract::CompareRequest* req,
             ::com::sekirocc::feature_extract::CompareResponse* resp) {
               return service->CompareFeature(ctx, req, resp);
             }, this)));
}

FaceService::Service::~Service() {
}

::grpc::Status FaceService::Service::Detect(::grpc::ServerContext* context, const ::com::sekirocc::feature_extract::DetectionRequest* request, ::com::sekirocc::feature_extract::DetectionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FaceService::Service::ExtractFeature(::grpc::ServerContext* context, const ::com::sekirocc::feature_extract::ExtractionRequest* request, ::com::sekirocc::feature_extract::ExtractionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FaceService::Service::CompareFeature(::grpc::ServerContext* context, const ::com::sekirocc::feature_extract::CompareRequest* request, ::com::sekirocc::feature_extract::CompareResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace com
}  // namespace sekirocc
}  // namespace feature_extract

