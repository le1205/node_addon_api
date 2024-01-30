#include <napi.h>
#include "DLMSTranslatorUtils.h"

class DLMSTranslatorUtilsWrapper : public Napi::ObjectWrap<DLMSTranslatorUtilsWrapper> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports); // Declaration of static Init method
  DLMSTranslatorUtilsWrapper(const Napi::CallbackInfo& info);

  // Public methods
  Napi::Value GetSystemTitle(const Napi::CallbackInfo& info);
  void SetSystemTitle(const Napi::CallbackInfo& info);
  Napi::Value GetBlockCipherKey(const Napi::CallbackInfo& info);
  void SetBlockCipherKey(const Napi::CallbackInfo& info);
  Napi::Value GetAuthenticationKey(const Napi::CallbackInfo& info);
  void SetAuthenticationKey(const Napi::CallbackInfo& info);
  Napi::Value DecryptPdu(const Napi::CallbackInfo& info);
  Napi::Value EncryptPdu(const Napi::CallbackInfo& info);
  Napi::Value PduToXml(const Napi::CallbackInfo& info);
  Napi::Value XmlToPdu(const Napi::CallbackInfo& info);

 private:
  static Napi::FunctionReference constructor;
  DLMSTranslatorUtils translator;
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
    InstanceMethod("getBlockCipherKey", &DLMSTranslatorUtilsWrapper::GetBlockCipherKey),
    InstanceMethod("setBlockCipherKey", &DLMSTranslatorUtilsWrapper::SetBlockCipherKey),
    InstanceMethod("getAuthenticationKey", &DLMSTranslatorUtilsWrapper::GetAuthenticationKey),
    InstanceMethod("setAuthenticationKey", &DLMSTranslatorUtilsWrapper::SetAuthenticationKey),
    InstanceMethod("decryptPdu", &DLMSTranslatorUtilsWrapper::DecryptPdu),
    InstanceMethod("encryptPdu", &DLMSTranslatorUtilsWrapper::EncryptPdu),
    InstanceMethod("pduToXml", &DLMSTranslatorUtilsWrapper::PduToXml),
    InstanceMethod("xmlToPdu", &DLMSTranslatorUtilsWrapper::XmlToPdu)
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

    // Call the standalone function
    std::string title = translator.GetSystemTitle();

    // Convert the std::string to a const char*
    const char* result = title.c_str();

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

// SetBlockCipherKey method implementation
void DLMSTranslatorUtilsWrapper::SetBlockCipherKey(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    return;
  }

  std::string setBlockCipherKey = info[0].As<Napi::String>().Utf8Value();
  translator.SetBlockCipherKey((char*)setBlockCipherKey.c_str());
}

// GetBlockCipherKey method implementation
Napi::Value DLMSTranslatorUtilsWrapper::GetBlockCipherKey(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // Call the standalone function
    std::string title = translator.GetBlockCipherKey();

    // Convert the std::string to a const char*
    const char* result = title.c_str();

    return Napi::String::New(env, result);
}

// SetAuthenticationKey method implementation
void DLMSTranslatorUtilsWrapper::SetAuthenticationKey(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    return;
  }

  std::string SetAuthenticationKey = info[0].As<Napi::String>().Utf8Value();
  translator.SetAuthenticationKey((char*)SetAuthenticationKey.c_str());
}

// GetAuthenticationKey method implementation
Napi::Value DLMSTranslatorUtilsWrapper::GetAuthenticationKey(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    // Call the standalone function
    std::string title = translator.GetAuthenticationKey();

    // Convert the std::string to a const char*
    const char* result = title.c_str();

    return Napi::String::New(env, result);
}



// DecryptPdu
Napi::Value DLMSTranslatorUtilsWrapper::DecryptPdu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // Check for correct number of arguments and types
  if (info.Length() < 3 || !info[0].IsString() || !info[1].IsString() || !info[2].IsBoolean()) {
    Napi::TypeError::New(env, "String, String and Boolean expected").ThrowAsJavaScriptException();
    return env.Null();
  }

  std::string data = info[0].As<Napi::String>().Utf8Value();
  std::string output = info[1].As<Napi::String>().Utf8Value();
  bool addSpaces = info[2].As<Napi::Boolean>().Value();

  int result = translator.DecryptPdu(data.c_str(), output, addSpaces);

  // Return an object containing the result and output
  Napi::Object resultObj = Napi::Object::New(env);
  resultObj.Set("status", Napi::Number::New(env, result));
  resultObj.Set("output", Napi::String::New(env, output));

  return resultObj;
}

// EncryptPdu
Napi::Value DLMSTranslatorUtilsWrapper::EncryptPdu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // Check for the correct number of arguments and types
  if (info.Length() < 3 || !info[0].IsString() || !info[1].IsString() || !info[2].IsBoolean()) {
    Napi::TypeError::New(env, "String, String, and Boolean expected").ThrowAsJavaScriptException();
    return env.Null();
  }

  std::string data = info[0].As<Napi::String>().Utf8Value();
  std::string output; // Output will be set by EncryptPdu function
  bool addSpaces = info[2].As<Napi::Boolean>().Value();

  // Call EncryptPdu function
  int result = translator.EncryptPdu(data.c_str(), output, addSpaces);

  // Return an object containing the result and output
  Napi::Object resultObj = Napi::Object::New(env);
  resultObj.Set("status", Napi::Number::New(env, result));
  resultObj.Set("output", Napi::String::New(env, output));

  return resultObj;
}

// XmlToPdu
Napi::Value DLMSTranslatorUtilsWrapper::XmlToPdu(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // Check for the correct number of arguments and types
  if (info.Length() < 3 || !info[0].IsString() || !info[1].IsString() || !info[2].IsBoolean()) {
    Napi::TypeError::New(env, "String, String, and Boolean expected").ThrowAsJavaScriptException();
    return env.Null();
  }

  std::string data = info[0].As<Napi::String>().Utf8Value();
  std::string output; // Output will be set by XmlToPdu function
  bool addSpaces = info[2].As<Napi::Boolean>().Value();

  // Call XmlToPdu function
  int result = translator.XmlToPdu(data.c_str(), output, addSpaces);

  // Return an object containing the result and output
  Napi::Object resultObj = Napi::Object::New(env);
  resultObj.Set("status", Napi::Number::New(env, result));
  resultObj.Set("output", Napi::String::New(env, output));

  return resultObj;
}

// Call PDU function
Napi::Value DLMSTranslatorUtilsWrapper::PduToXml(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  // Check the number and type of arguments
  if (info.Length() < 1 || !info[0].IsString()) {
    Napi::TypeError::New(env, "String expected").ThrowAsJavaScriptException();
    return env.Null(); // Return null in case of an error
  }

  std::string data = info[0].As<Napi::String>().Utf8Value();
  std::string output; // This will store the XML output

  // Call the PduToXml function and get the result
  int result = translator.PduToXml(data.c_str(), output);

  // Create a JavaScript object to hold the result and output
  Napi::Object resultObj = Napi::Object::New(env);
  resultObj.Set("status", Napi::Number::New(env, result));
  resultObj.Set("output", Napi::String::New(env, output));

  // Return the result object
  return resultObj;
}


//

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return DLMSTranslatorUtilsWrapper::Init(env, exports);
}

// ... Implement other methods similarly ...

NODE_API_MODULE(addon, InitAll)
