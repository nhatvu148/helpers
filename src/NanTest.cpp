#include <nan.h>
// #include "MyObject.h"
// #include "FactoryWrap.h"
#include "PassWrap.h"

void Method(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  info.GetReturnValue().Set(Nan::New("world").ToLocalChecked());
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
  //              Nan::New("add").ToLocalChecked(),
  //              Nan::New<v8::FunctionTemplate>(Add)
  //                  ->GetFunction(context)
  //                  .ToLocalChecked());

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

  MyObject::Init();
  exports->Set(context,
               Nan::New("createObject").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(CreateObject2)
                   ->GetFunction(context)
                   .ToLocalChecked());
  exports->Set(context,
               Nan::New("add").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Add2)
                   ->GetFunction(context)
                   .ToLocalChecked());
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)