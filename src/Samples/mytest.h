#include <napi.h>

namespace mytest
{
    std::string hello(std::string name, int age);
    Napi::String HelloWrapped(const Napi::CallbackInfo &info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);
} // namespace test