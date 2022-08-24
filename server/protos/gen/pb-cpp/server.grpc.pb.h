// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: server.proto
#ifndef GRPC_server_2eproto__INCLUDED
#define GRPC_server_2eproto__INCLUDED

#include "server.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace com {
namespace sekirocc {
namespace face_service {

// face service
class FaceService final {
 public:
  static constexpr char const* service_full_name() {
    return "com.sekirocc.face_service.FaceService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::com::sekirocc::face_service::DetectionResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::DetectionResponse>> AsyncDetect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::DetectionResponse>>(AsyncDetectRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::DetectionResponse>> PrepareAsyncDetect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::DetectionResponse>>(PrepareAsyncDetectRaw(context, request, cq));
    }
    virtual ::grpc::Status ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::com::sekirocc::face_service::ExtractionResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::ExtractionResponse>> AsyncExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::ExtractionResponse>>(AsyncExtractFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::ExtractionResponse>> PrepareAsyncExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::ExtractionResponse>>(PrepareAsyncExtractFeatureRaw(context, request, cq));
    }
    virtual ::grpc::Status CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::com::sekirocc::face_service::CompareResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::CompareResponse>> AsyncCompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::CompareResponse>>(AsyncCompareFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::CompareResponse>> PrepareAsyncCompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::CompareResponse>>(PrepareAsyncCompareFeatureRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response, std::function<void(::grpc::Status)>) = 0;
      virtual void CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::DetectionResponse>* AsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::DetectionResponse>* PrepareAsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::ExtractionResponse>* AsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::ExtractionResponse>* PrepareAsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::CompareResponse>* AsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::com::sekirocc::face_service::CompareResponse>* PrepareAsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::com::sekirocc::face_service::DetectionResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>> AsyncDetect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>>(AsyncDetectRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>> PrepareAsyncDetect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>>(PrepareAsyncDetectRaw(context, request, cq));
    }
    ::grpc::Status ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::com::sekirocc::face_service::ExtractionResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>> AsyncExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>>(AsyncExtractFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>> PrepareAsyncExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>>(PrepareAsyncExtractFeatureRaw(context, request, cq));
    }
    ::grpc::Status CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::com::sekirocc::face_service::CompareResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>> AsyncCompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>>(AsyncCompareFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>> PrepareAsyncCompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>>(PrepareAsyncCompareFeatureRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response, std::function<void(::grpc::Status)>) override;
      void Detect(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response, std::function<void(::grpc::Status)>) override;
      void ExtractFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      void CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response, std::function<void(::grpc::Status)>) override;
      void CompareFeature(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>* AsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::DetectionResponse>* PrepareAsyncDetectRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::DetectionRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>* AsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::ExtractionResponse>* PrepareAsyncExtractFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::ExtractionRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>* AsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::com::sekirocc::face_service::CompareResponse>* PrepareAsyncCompareFeatureRaw(::grpc::ClientContext* context, const ::com::sekirocc::face_service::CompareRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Detect_;
    const ::grpc::internal::RpcMethod rpcmethod_ExtractFeature_;
    const ::grpc::internal::RpcMethod rpcmethod_CompareFeature_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Detect(::grpc::ServerContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response);
    virtual ::grpc::Status ExtractFeature(::grpc::ServerContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response);
    virtual ::grpc::Status CompareFeature(::grpc::ServerContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Detect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_Detect() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Detect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Detect(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDetect(::grpc::ServerContext* context, ::com::sekirocc::face_service::DetectionRequest* request, ::grpc::ServerAsyncResponseWriter< ::com::sekirocc::face_service::DetectionResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ExtractFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_ExtractFeature() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_ExtractFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ExtractFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestExtractFeature(::grpc::ServerContext* context, ::com::sekirocc::face_service::ExtractionRequest* request, ::grpc::ServerAsyncResponseWriter< ::com::sekirocc::face_service::ExtractionResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_CompareFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_CompareFeature() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_CompareFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CompareFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCompareFeature(::grpc::ServerContext* context, ::com::sekirocc::face_service::CompareRequest* request, ::grpc::ServerAsyncResponseWriter< ::com::sekirocc::face_service::CompareResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Detect<WithAsyncMethod_ExtractFeature<WithAsyncMethod_CompareFeature<Service > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_Detect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_Detect() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::com::sekirocc::face_service::DetectionRequest* request, ::com::sekirocc::face_service::DetectionResponse* response) { return this->Detect(context, request, response); }));}
    void SetMessageAllocatorFor_Detect(
        ::grpc::MessageAllocator< ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_Detect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Detect(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* Detect(
      ::grpc::CallbackServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_ExtractFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_ExtractFeature() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::com::sekirocc::face_service::ExtractionRequest* request, ::com::sekirocc::face_service::ExtractionResponse* response) { return this->ExtractFeature(context, request, response); }));}
    void SetMessageAllocatorFor_ExtractFeature(
        ::grpc::MessageAllocator< ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(1);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_ExtractFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ExtractFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* ExtractFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_CompareFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_CompareFeature() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::com::sekirocc::face_service::CompareRequest* request, ::com::sekirocc::face_service::CompareResponse* response) { return this->CompareFeature(context, request, response); }));}
    void SetMessageAllocatorFor_CompareFeature(
        ::grpc::MessageAllocator< ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(2);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_CompareFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CompareFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CompareFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_Detect<WithCallbackMethod_ExtractFeature<WithCallbackMethod_CompareFeature<Service > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Detect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_Detect() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Detect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Detect(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ExtractFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_ExtractFeature() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_ExtractFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ExtractFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_CompareFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_CompareFeature() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_CompareFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CompareFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Detect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_Detect() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Detect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Detect(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestDetect(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_ExtractFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_ExtractFeature() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_ExtractFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ExtractFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestExtractFeature(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_CompareFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_CompareFeature() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_CompareFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CompareFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestCompareFeature(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(2, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_Detect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_Detect() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->Detect(context, request, response); }));
    }
    ~WithRawCallbackMethod_Detect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Detect(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* Detect(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_ExtractFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_ExtractFeature() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->ExtractFeature(context, request, response); }));
    }
    ~WithRawCallbackMethod_ExtractFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ExtractFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* ExtractFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_CompareFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_CompareFeature() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->CompareFeature(context, request, response); }));
    }
    ~WithRawCallbackMethod_CompareFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status CompareFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* CompareFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Detect : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_Detect() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::com::sekirocc::face_service::DetectionRequest, ::com::sekirocc::face_service::DetectionResponse>* streamer) {
                       return this->StreamedDetect(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_Detect() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Detect(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::DetectionRequest* /*request*/, ::com::sekirocc::face_service::DetectionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedDetect(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::com::sekirocc::face_service::DetectionRequest,::com::sekirocc::face_service::DetectionResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_ExtractFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_ExtractFeature() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler<
          ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::com::sekirocc::face_service::ExtractionRequest, ::com::sekirocc::face_service::ExtractionResponse>* streamer) {
                       return this->StreamedExtractFeature(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_ExtractFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status ExtractFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::ExtractionRequest* /*request*/, ::com::sekirocc::face_service::ExtractionResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedExtractFeature(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::com::sekirocc::face_service::ExtractionRequest,::com::sekirocc::face_service::ExtractionResponse>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_CompareFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_CompareFeature() {
      ::grpc::Service::MarkMethodStreamed(2,
        new ::grpc::internal::StreamedUnaryHandler<
          ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::com::sekirocc::face_service::CompareRequest, ::com::sekirocc::face_service::CompareResponse>* streamer) {
                       return this->StreamedCompareFeature(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_CompareFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status CompareFeature(::grpc::ServerContext* /*context*/, const ::com::sekirocc::face_service::CompareRequest* /*request*/, ::com::sekirocc::face_service::CompareResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedCompareFeature(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::com::sekirocc::face_service::CompareRequest,::com::sekirocc::face_service::CompareResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Detect<WithStreamedUnaryMethod_ExtractFeature<WithStreamedUnaryMethod_CompareFeature<Service > > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Detect<WithStreamedUnaryMethod_ExtractFeature<WithStreamedUnaryMethod_CompareFeature<Service > > > StreamedService;
};

}  // namespace face_service
}  // namespace sekirocc
}  // namespace com


#endif  // GRPC_server_2eproto__INCLUDED
