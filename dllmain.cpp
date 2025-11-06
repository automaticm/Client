#include "jni/jni.h"
#include <Windows.h>
#include <iostream>

FILE* file = nullptr;
JavaVM* vm;
JNIEnv* env = NULL;

void init(HMODULE module) {
    AllocConsole();
    freopen_s(&file, "CONOUT$", "w", stdout);
    printf("Successfully injected.\n");

    jsize vmSize;
    if(JNI_GetCreatedJavaVMs(&vm, 1, &vmSize) != JNI_OK || vmSize == 0){
        printf("JVM not located\n"); return;
    }

    jint res = vm->GetEnv((void**)&env, JNI_VERSION_1_6);
    if(res == JNI_EDETACHED){
        res = vm->AttachCurrentThread((void**)&env, nullptr);
    }
    if (res != JNI_OK){
        printf("Cannot setup JNI.\n"); return;
    }

    if(env != nullptr){
        printf("JNI hooked.\n");
    }


}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:{
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)init, hModule, 0, 0);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

