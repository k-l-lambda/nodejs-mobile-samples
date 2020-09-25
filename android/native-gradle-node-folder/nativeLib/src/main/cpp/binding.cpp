#include <v8.h>
#include <node.h>

#include "./SayWorker.h"



static int c = 0;


void Hello(const v8::FunctionCallbackInfo<v8::Value>& args) {
	args.GetReturnValue().Set(c++);
}


void Say(const v8::FunctionCallbackInfo<v8::Value>& args) {
	v8::Local<v8::Object> what = args[0].As<v8::Object>();

	auto context = args.GetIsolate()->GetCurrentContext();

	auto maybe_resolver = v8::Promise::Resolver::New(context);
	v8::Local<v8::Promise::Resolver> resolver;
	if (maybe_resolver.ToLocal(&resolver)) {
		Nan::Persistent<v8::Promise::Resolver>* persistent = new Nan::Persistent<v8::Promise::Resolver>(resolver);

		SayWorker *sw = new SayWorker(context, persistent, 1, what);
		Nan::AsyncQueueWorker(sw);

		args.GetReturnValue().Set(resolver->GetPromise());
	}
	else
		args.GetReturnValue().Set(0);
}


void Initialize(v8::Local<v8::Object> target) {
	NODE_SET_METHOD(target, "hello", Hello);
	NODE_SET_METHOD(target, "say", Say);
}


NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
