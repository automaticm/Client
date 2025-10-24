#pragma once
#include "JNI/jni.h"

namespace jvm{
	void load();
		JavaVM* vm = nullptr;
		JNIEnv* environment = nullptr;
		JavaVMInitArgs args;
}

class c_jobject
{
public:
	c_jobject(jobject object_in);
	~c_jobject();

	jobject cached_object = nullptr;
};