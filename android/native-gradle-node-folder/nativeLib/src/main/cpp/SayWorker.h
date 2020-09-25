#ifndef SayWorker_H
#define SayWorker_H



#include <nan.h>



class SayWorker : public Nan::AsyncWorker
{
public:
	SayWorker(Nan::Persistent<v8::Context>* context, Nan::Persistent<v8::Promise::Resolver>* persistent, int wait, v8::Local<v8::Object> &whatObj);

private:
	~SayWorker();

	virtual void Execute();
	virtual void HandleOKCallback ();

	Nan::Persistent<v8::Context>* _context;
	int _wait;
	std::string _what;
	std::string _result;
	Nan::Persistent<v8::Promise::Resolver>* _persistent;
};



#endif	// SayWorker_H
