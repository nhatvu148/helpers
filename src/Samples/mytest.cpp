#include "mytest.h"
#include <string>

std::string mytest::hello(std::string name, int age)
{
    return "Hello " + name + "\nYou are " + std::to_string(age) + " years old!";
}

Napi::String mytest::HelloWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, "String and Number expected").ThrowAsJavaScriptException();
    }

    Napi::String first = info[0].As<Napi::String>();
    int second = info[1].As<Napi::Number>();
    Napi::String returnValue = Napi::String::New(env, mytest::hello(first, second));

    return returnValue;
}

Napi::Object mytest::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set(
        "hello", Napi::Function::New(env, mytest::HelloWrapped));

    return exports;
}