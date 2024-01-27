#include <napi.h>
#include "DLMSTranslatorUtils.h"

class DLMSTranslatorUtilsWrapper : public Napi::ObjectWrap<DLMSTranslatorUtilsWrapper> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports); // Declaration of static Init method
  DLMSTranslatorUtilsWrapper(const Napi::CallbackInfo& info);

  // Public methods
  Napi::Value GetSystemTitle(const Napi::CallbackInfo& info);
  void SetSystemTitle(const Napi::CallbackInfo& info);
  Napi::Value DecryptPdu(const Napi::CallbackInfo& info);
  Napi::Value encryptPdu(const Napi::CallbackInfo& info);
  int PduToXml(const Napi::CallbackInfo& info);
  int XmlToPdu(const Napi::CallbackInfo& info);
  

 private:
  static Napi::FunctionReference constructor;
  DLMSTranslatorUtils translator;
  // ... other private members and methods
};

Napi::FunctionReference DLMSTranslatorUtilsWrapper::constructor;

// Constructor implementation
DLMSTranslatorUtilsWrapper::DLMSTranslatorUtilsWrapper(const Napi::CallbackInfo& info) : Napi::ObjectWrap<DLMSTranslatorUtilsWrapper>(info) {
  // Constructor logic...
}

// Init method implementation (no 'static' keyword here)
Napi::Object DLMSTranslatorUtilsWrapper::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);
  Napi::Function func = DefineClass(env, "DLMSTranslatorUtilsWrapper", {
    InstanceMethod("getSystemTitle", &DLMSTranslatorUtilsWrapper::GetSystemTitle),
    InstanceMethod("setSystemTitle", &DLMSTranslatorUtilsWrapper::SetSystemTitle),
    InstanceMethod("decryptPdu", &DLMSTranslatorUtilsWrapper::DecryptPdu),
    InstanceMethod("encryptPdu", &DLMSTranslatorUtilsWrapper::EncryptPdu),
    // ... other method bindings
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("DLMSTranslatorUtilsWrapper", func);
  return exports;
}

// GetSystemTitle method implementation
Napi::Value DLMSTranslatorUtilsWrapper::GetSystemTitle(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // Call the C++ method
  const char* result = translator.GetSystemTitle();

  return Napi::String::New(env, result);
}

// SetSystemTitle method implementation
void DLMSTranslatorUtilsWrapper::SetSystemTitle(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    return;
  }

  std::string systemTitle = info[0].As<Napi::String>().Utf8Value();
  translator.SetSystemTitle((char*)systemTitle.c_str());
}

// DecryptPdu
Napi::Value DLMSTranslatorUtilsWrapper::DecryptPdu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // if (info.Length() < 1 || !info[0].IsString()) {
  //   Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
  //   return -1;
  // }

  std::string data = info[0].As<Napi::String>().Utf8Value();
  std::string output = info[1].As<Napi::String>().Utf8Value();

  translator.DecryptPdu((char*)data.c_str(), output);

  return Napi::String::New(env, (char*)data.c_str());
}

// EncryptPdu
Napi::Value DLMSTranslatorUtilsWrapper::EncryptPdu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // if (info.Length() < 1 || !info[0].IsString()) {
  //   Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
  //   return -1;
  // }

  std::string data = info[0].As<Napi::String>().Utf8Value();
  std::string output = info[1].As<Napi::String>().Utf8Value();

  translator.EecryptPdu((char*)data.c_str(), output);

  return Napi::String::New(env, (char*)data.c_str());
}


Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return DLMSTranslatorUtilsWrapper::Init(env, exports);
}

// ... Implement other methods similarly ...

NODE_API_MODULE(dlms_translator_utils_extension, InitAll)
