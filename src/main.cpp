#include <nan.h>
// #include "MyObject.h"
// #include "FactoryWrap.h"
#include "PassWrap.h"
#include <fstream>
#include <string>
#include "v8pp/module.hpp"

void Method(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
}

void Calculate(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  int i;
  double x = 122.34;
  double y = 203.54;

  for (i = 0; i < 1000000000; i++)
  {
    x += y;
  }

  auto total = Nan::New(x);
  std::ofstream logFile("logfile.txt");
  printf("Hello from C++ is %f\n", x);
  logFile << "Result is " << std::to_string(1234) << " " << x;
  info.GetReturnValue().Set(total);
}

void PassNumber(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  double value = info[0]->NumberValue(context).FromJust();

  v8::Local<v8::Number> retval = Nan::New(value + 1234);
  info.GetReturnValue().Set(retval);
}

void PassInteger(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  double value = info[0]->NumberValue(context).FromJust();

  v8::Local<v8::Number> retval = Nan::New(value + 1);
  info.GetReturnValue().Set(retval);
}

void Add2Numbers(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  double value1 = info[0]->NumberValue(context).FromJust();
  double value2 = info[1]->NumberValue(context).FromJust();

  v8::Local<v8::Number> retval = Nan::New(value1 + value2);
  info.GetReturnValue().Set(retval);
}

void PassBoolean(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Isolate *isolate = info.GetIsolate();
  v8::Local<v8::Boolean> target = info[0]->ToBoolean(v8::Isolate::GetCurrent());
  bool value = target.As<v8::Boolean>()->Value();

  v8::Local<v8::Boolean> retval = v8::Boolean::New(isolate, !value);
  info.GetReturnValue().Set(retval);
}

void PassString(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::String::Utf8Value s(v8::Isolate::GetCurrent(), info[0]);
  std::string str(*s, s.length());
  std::reverse(str.begin(), str.end());

  v8::Local<v8::String> retval = Nan::New(str.c_str()).ToLocalChecked();
  info.GetReturnValue().Set(retval);
}

void PassObject(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Isolate *isolate = info.GetIsolate();
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
  v8::Local<v8::Object> target = info[0]->ToObject(isolate->GetCurrentContext()).ToLocalChecked();

  std::vector<int> vector{1, 2, 3};
  v8::Local<v8::Array> v8_vector = v8pp::to_v8(isolate, vector);

  std::map<std::string, int> map{{"a", 10}, {"b", 12}};
  v8::Local<v8::Object> v8_map = v8pp::to_v8(isolate, map);

  auto v = v8pp::from_v8<std::vector<int>>(isolate, v8_vector);
  auto m = v8pp::from_v8<std::map<std::string, int>>(isolate, v8_map);
  for (const auto &elem : m)
  {
    printf("%s\n", elem.first);
    printf("%d\n", elem.second);
  }
  info.GetReturnValue().Set(target);
}

void Add(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  if (info.Length() < 2)
  {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }

  if (!info[0]->IsNumber() || !info[1]->IsNumber())
  {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }

  double arg0 = info[0]->NumberValue(context).FromJust();
  double arg1 = info[1]->NumberValue(context).FromJust();
  v8::Local<v8::Number> num = Nan::New(arg0 + arg1);

  info.GetReturnValue().Set(num);
}

void RunCallback(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Function> cb = info[0].As<v8::Function>();
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = {Nan::New("hello world").ToLocalChecked()};
  Nan::AsyncResource resource("nan:makeCallback");
  resource.runInAsyncScope(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}

void CreateObject(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
  v8::Local<v8::Object> obj = Nan::New<v8::Object>();
  obj->Set(context,
           Nan::New("msg").ToLocalChecked(),
           info[0]->ToString(context).ToLocalChecked());

  info.GetReturnValue().Set(obj);
}

void MyFunction(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  info.GetReturnValue().Set(Nan::New("Hello New World!").ToLocalChecked());
}

void CreateFunction(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
  v8::Local<v8::FunctionTemplate> tpl =
      Nan::New<v8::FunctionTemplate>(MyFunction);
  v8::Local<v8::Function> fn = tpl->GetFunction(context).ToLocalChecked();

  // omit this to make it anonymous
  fn->SetName(Nan::New("theFunction").ToLocalChecked());

  info.GetReturnValue().Set(fn);
}

void CreateObject2(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  info.GetReturnValue().Set(MyObject::NewInstance(info[0]));
}

void Add2(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  MyObject *obj1 = Nan::ObjectWrap::Unwrap<MyObject>(
      info[0]->ToObject(context).ToLocalChecked());
  MyObject *obj2 = Nan::ObjectWrap::Unwrap<MyObject>(
      info[1]->ToObject(context).ToLocalChecked());
  double sum = obj1->Val() + obj2->Val();
  info.GetReturnValue().Set(Nan::New(sum));
}

void Initialize(v8::Local<v8::Object> exports, v8::Local<v8::Object> module)
{
  v8::Local<v8::Context> context = exports->CreationContext();
  // exports->Set(context,
  //              Nan::New("hello").ToLocalChecked(),
  //              Nan::New<v8::FunctionTemplate>(Method)
  //                  ->GetFunction(context)
  //                  .ToLocalChecked());
  // exports->Set(context,
  //              Nan::New("calc").ToLocalChecked(),
  //              Nan::New<v8::FunctionTemplate>(Calculate)
  //                  ->GetFunction(context)
  //                  .ToLocalChecked());
  // exports->Set(context,
  //              Nan::New("add").ToLocalChecked(),
  //              Nan::New<v8::FunctionTemplate>(Add)
  //                  ->GetFunction(context)
  //                  .ToLocalChecked());
  exports->Set(context,
               Nan::New("pass_number").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(PassNumber)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("pass_integer").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(PassInteger)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("add_2_numbers").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add2Numbers)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("pass_boolean").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(PassBoolean)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("pass_string").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(PassString)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("pass_object").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(PassObject)
                   ->GetFunction(context)
                   .ToLocalChecked());

  // module->Set(context,
  //             Nan::New("exports").ToLocalChecked(),
  //             Nan::New<v8::FunctionTemplate>(CreateObject)
  //                 ->GetFunction(context)
  //                 .ToLocalChecked());
  // Nan::SetMethod(module, "exports", CreateObject);

  // module->Set(context,
  //             Nan::New("exports").ToLocalChecked(),
  //             Nan::New<v8::FunctionTemplate>(RunCallback)
  //                 ->GetFunction(context)
  //                 .ToLocalChecked());
  // Nan::SetMethod(module, "exports", RunCallback);

  // Nan::SetMethod(module, "exports", CreateFunction);

  // MyObject::Init(exports);

  // Nan::HandleScope scope;
  // MyObject::Init();
  // module->Set(context,
  //             Nan::New("exports").ToLocalChecked(),
  //             Nan::New<v8::FunctionTemplate>(CreateObject2)
  //                 ->GetFunction(context)
  //                 .ToLocalChecked());

  // MyObject::Init();
  // exports->Set(context,
  //              Nan::New("createObject").ToLocalChecked(),
  //              Nan::New<v8::FunctionTemplate>(CreateObject2)
  //                  ->GetFunction(context)
  //                  .ToLocalChecked());
  // exports->Set(context,
  //              Nan::New("add").ToLocalChecked(),
  //              Nan::New<v8::FunctionTemplate>(Add2)
  //                  ->GetFunction(context)
  //                  .ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)