#include <v8.h>
#include <node.h>

#include "./SayWorker.h"



static int c = 0;


void Hello(const v8::FunctionCallbackInfo<v8::Value>& args) {
	args.GetReturnValue().Set(c++);
}


void Say(const v8::FunctionCallbackInfo<v8::Value>& info) {
//NAN_METHOD(Say) {
	//Nan::HandleScope scope;

	v8::Local<v8::Object> what = info[0].As<v8::Object>();

	auto context = info.GetIsolate()->GetCurrentContext();

	auto maybe_resolver = v8::Promise::Resolver::New(context);
	v8::Local<v8::Promise::Resolver> resolver;
	if (maybe_resolver.ToLocal(&resolver)) {
		Nan::Persistent<v8::Promise::Resolver>* persistent = new Nan::Persistent<v8::Promise::Resolver>(resolver);
		auto pcontext = new Nan::Persistent<v8::Context>(context);

		SayWorker *sw = new SayWorker(pcontext, persistent, 1, what);
		Nan::AsyncQueueWorker(sw);

		info.GetReturnValue().Set(resolver->GetPromise());
	}
	else
		info.GetReturnValue().Set(0);
}


void Initialize(v8::Local<v8::Object> target) {
	NODE_SET_METHOD(target, "hello", Hello);
	NODE_SET_METHOD(target, "say", Say);
	//Nan::Set(target, Nan::New<v8::String>("say").ToLocalChecked(),
	//	Nan::GetFunction(Nan::New<v8::FunctionTemplate>(Say)).ToLocalChecked());
}


NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
