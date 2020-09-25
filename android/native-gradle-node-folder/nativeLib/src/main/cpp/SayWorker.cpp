
#include <unistd.h>

#include "SayWorker.h"



SayWorker::SayWorker(v8::Local<v8::Context> context, Nan::Persistent<v8::Promise::Resolver> *persistent, int wait, v8::Local<v8::Object> &whatObj)
	: AsyncWorker(NULL)
	, _context(context)
{
	_wait = wait;
	_what = std::string(*Nan::Utf8String(whatObj));
	_persistent = persistent;
}

SayWorker::~SayWorker() {}

void SayWorker::Execute () {
	//sleep(_wait);

	_result = "says: " + _what;
}

void SayWorker::HandleOKCallback () {
	Nan::HandleScope scope;
	auto resolver = Nan::New(*_persistent);
	auto result = resolver->Resolve(_context, Nan::New(_result).ToLocalChecked());
	(void)result;
}
