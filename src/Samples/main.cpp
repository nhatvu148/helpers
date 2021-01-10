#include <napi.h>
#include "Samples/functionexample.h"
#include "Samples/classexample.h"
#include "Samples/mytest.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    functionexample::Init(env, exports);
    ClassExample::Init(env, exports);
    return mytest::Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)