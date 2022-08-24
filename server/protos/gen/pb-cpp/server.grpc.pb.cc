// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: server.proto

#include "server.pb.h"
#include "server.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace com {
namespace sekirocc {
namespace face_service {

static const char* FaceService_method_names[] = {
  "/com.sekirocc.face_service.FaceService/Detect",
  "/com.sekirocc.face_service.FaceService/ExtractFeature",
  "/com.sekirocc.face_service.FaceService/CompareFeature",
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

::grpc::Status FaceService::Stub::Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::com::sekirocc::face_service::DetectionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_Detect_, context, request, response);
}

void FaceService::Stub::async::Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Detect_, context, request, response, std::move(f));
}

void FaceService::Stub::async::Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_Detect_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>* FaceService::Stub::PrepareAsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::com::sekirocc::face_service::DetectionResponse, ::com::sekirocc::face_service::DetectionRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_Detect_, context, request);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>* FaceService::Stub::AsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDetectRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FaceService::Stub::ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::com::sekirocc::face_service::ExtractionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_ExtractFeature_, context, request, response);
}

void FaceService::Stub::async::ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ExtractFeature_, context, request, response, std::move(f));
}

void FaceService::Stub::async::ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_ExtractFeature_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>* FaceService::Stub::PrepareAsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::com::sekirocc::face_service::ExtractionResponse, ::com::sekirocc::face_service::ExtractionRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_ExtractFeature_, context, request);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>* FaceService::Stub::AsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncExtractFeatureRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status FaceService::Stub::CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::com::sekirocc::face_service::CompareResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_CompareFeature_, context, request, response);
}

void FaceService::Stub::async::CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompareFeature_, context, request, response, std::move(f));
}

void FaceService::Stub::async::CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_CompareFeature_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>* FaceService::Stub::PrepareAsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::com::sekirocc::face_service::CompareResponse, ::com::sekirocc::face_service::CompareRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_CompareFeature_, context, request);
}

::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>* FaceService::Stub::AsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncCompareFeatureRaw(context, request, cq);
  result->StartCall();
  return result;
}

FaceService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FaceService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FaceService::Service, ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FaceService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::com::sekirocc::face_service::DetectionRequest* req,
             ::com::sekirocc::face_service::DetectionResponse* resp) {
               return service->Detect(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FaceService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FaceService::Service, ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FaceService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::com::sekirocc::face_service::ExtractionRequest* req,
             ::com::sekirocc::face_service::ExtractionResponse* resp) {
               return service->ExtractFeature(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      FaceService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< FaceService::Service, ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](FaceService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::com::sekirocc::face_service::CompareRequest* req,
             ::com::sekirocc::face_service::CompareResponse* resp) {
               return service->CompareFeature(ctx, req, resp);
             }, this)));
}

FaceService::Service::~Service() {
}

::grpc::Status FaceService::Service::Detect(::grpc::ServerContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FaceService::Service::ExtractFeature(::grpc::ServerContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status FaceService::Service::CompareFeature(::grpc::ServerContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace com
}  // namespace sekirocc
}  // namespace face_service

