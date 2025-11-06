#include "windows.h"
#include <iostream>
#include "jni/jni.h"

#define long long long
extern JavaVM* vm;
extern JNIEnv* env;

extern void client_main(HMODULE hModule);