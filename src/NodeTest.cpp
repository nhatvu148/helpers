#include <node.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "v8pp/module.hpp"

/* Demonstrates converstions of v8:Value's passed as arguments.
   See https://v8docs.nodesource.com/node-0.8/dc/d0a/classv8_1_1_value.html
   for more types and conversion methods
*/
v8::Local<v8::Value> make_return(v8::Isolate *isolate, const v8::Local<v8::Object> input);

void PassNumber(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();

    double value = args[0].As<v8::Number>()->Value();

    v8::Local<v8::Number> retval = v8::Number::New(isolate, value + 42);
    args.GetReturnValue().Set(retval);
}

void PassInteger(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();

    double value = args[0].As<v8::Int32>()->Value();

    v8::Local<v8::Number> retval = v8::Int32::New(isolate, value + 42);
    args.GetReturnValue().Set(retval);
}

void Add2Numbers(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();

    double value1 = args[0].As<v8::Number>()->Value();
    double value2 = args[1].As<v8::Number>()->Value();

    v8::Local<v8::Number> retval = v8::Number::New(isolate, value1 + value2);
    args.GetReturnValue().Set(retval);
}

void PassBoolean(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Boolean> target = args[0]->ToBoolean(v8::Isolate::GetCurrent());
    bool value = target.As<v8::Boolean>()->Value();

    v8::Local<v8::Boolean> retval = v8::Boolean::New(isolate, !value);
    args.GetReturnValue().Set(retval);
}

void PassString(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();

    v8::String::Utf8Value s(v8::Isolate::GetCurrent(), args[0]);
    std::string str(*s, s.length());
    std::reverse(str.begin(), str.end());

    v8::Local<v8::String> retval = v8::String::NewFromUtf8(isolate, str.c_str()).ToLocalChecked();
    args.GetReturnValue().Set(retval);
}

void PassObject(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = args.GetIsolate()->GetCurrentContext();
    v8::Local<v8::Object> target = args[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

    // v8::Local<v8::Value> obj = make_return(isolate, target);

    std::vector<int> vector{1, 2, 3};
    v8::Local<v8::Array> v8_vector = v8pp::to_v8(isolate, vector);

    std::map<std::string, int> map{{"a", 10}, {"b", 12}};
    v8::Local<v8::Object> v8_map = v8pp::to_v8(isolate, map);

    auto v = v8pp::from_v8<std::vector<int>>(isolate, v8_vector);
    auto m = v8pp::from_v8<std::map<std::string, int>>(isolate, v8_map);
    for (const auto& elem : m)
    {
        printf("%s\n", elem.first);
        printf("%d\n", elem.second);
    }
    args.GetReturnValue().Set(target);
}

// void PassArray(const v8::FunctionCallbackInfo<v8::Value> &args)
// {
//     v8::Isolate *isolate = args.GetIsolate();
//     v8::Local<v8::Array> array = v8::Local<v8::Array>::Cast(args[0]);

//     for (unsigned int i = 0; i < array->Length(); i++)
//     {
//         if (array->Has(i))
//         {
//             double value = array->Get(i)->NumberValue();
//             array->Set(i, v8::Number::New(isolate, value + 1));
//         }
//     }

//     v8::Local<v8::String> prop = v8::String::NewFromUtf8(isolate, "not_index");
//     v8::Local<v8::Array> a = v8::Array::New(isolate);
//     a->Set(0, array->Get(0));
//     a->Set(1, array->Get(prop));
//     a->Set(2, array->Get(2));

//     args.GetReturnValue().Set(a);
// }

// v8::Local<v8::Value> make_return(v8::Isolate *isolate, const v8::Local<v8::Object> input)
// {
//     v8::Local<v8::String> x_prop = v8::String::NewFromUtf8(isolate, "x").ToLocalChecked();
//     v8::Local<v8::String> y_prop = v8::String::NewFromUtf8(isolate, "y").ToLocalChecked();
//     v8::Local<v8::String> sum_prop = v8::String::NewFromUtf8(isolate, "sum").ToLocalChecked();
//     v8::Local<v8::String> product_prop = v8::String::NewFromUtf8(isolate, "product").ToLocalChecked();

//     double x = input->Get(x_prop).As<v8::Number>()->Value();
//     double y = input->Get(y_prop).As<v8::Number>()->Value();

//     v8::Local<v8::Object> obj = v8::Object::New(isolate);
//     obj->Set(sum_prop, v8::Number::New(isolate, x + y));
//     obj->Set(product_prop, v8::Number::New(isolate, x * y));
//     return obj;
// }

void Initialize(v8::Local<v8::Object> exports)
{
    NODE_SET_METHOD(exports, "pass_number", PassNumber);
    NODE_SET_METHOD(exports, "pass_integer", PassInteger);
    NODE_SET_METHOD(exports, "add_2_numbers", Add2Numbers);
    NODE_SET_METHOD(exports, "pass_boolean", PassBoolean);
    NODE_SET_METHOD(exports, "pass_string", PassString);
    NODE_SET_METHOD(exports, "pass_object", PassObject);
    // NODE_SET_METHOD(exports, "pass_array", PassArray);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
