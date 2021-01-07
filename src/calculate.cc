#include <node.h>
#include "v8pp/module.hpp"
#include <fstream>
#include <string>
#include <sstream>

void Method(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();

    int i;
    double x = 122.34;
    double y = 203.54;

    for (i = 0; i < 1000000000; i++)
    {
        x += y;
    }

    auto total = v8pp::to_v8(isolate, x);

    // std::stringstream ss;
    // ss << "Result is ";
    // ss << total;

    // std::string info = ss.str();

    std::ofstream logFile("logfile.txt");
    printf("Hello from C++ is %d", v8pp::from_v8<int>(isolate, total));
    logFile << "Result is " << std::to_string(12) << " " << x;
    // args.GetReturnValue().Set(total); //// Same as x
    args.GetReturnValue().Set(x);
}

void Initialize(v8::Local<v8::Object> exports)
{
    NODE_SET_METHOD(exports, "calc", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
