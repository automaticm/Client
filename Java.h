#pragma once
#include "JNI/jni.h"

class cheetos
{
public:
	JavaVM* vm;
	JNIEnv* environment;
	JavaVMInitArgs args;
}cheeto;