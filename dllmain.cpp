#include <Windows.h>
#include <iostream>

#include "main.h"
#include "jni/jni.h"

FILE* file = nullptr;
JavaVM* vm;
JNIEnv* env = NULL;

void init(HMODULE hModule) {
    AllocConsole();
    freopen_s(&file, "CONOUT$", "w", stdout);
    printf("Successfully injected.\n");

    Sleep(1000);
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
        client_main(hModule);
        // // Setting up Minecraft instance
        // jclass minecraftClass = env->FindClass("ave");
        // // if (minecraftClass == NULL) {
        // //     printf("Failed to find class 'ave'.\n");
        // //     return;
        // //}
        // jmethodID getMinecraft = env->GetStaticMethodID(minecraftClass, "A", "()Lave;");
        // // if (getMinecraft == NULL) {
        // //     printf("Failed to find method 'A'.\n");
        // //     return;
        // // }
        // jobject minecraftInstance = env->CallStaticObjectMethod(minecraftClass, getMinecraft);
        
        // // Player attributes
        // jfieldID plrField = env->GetFieldID(minecraftClass, "h", "Lbew;");
        // // if (plrField == NULL) {
        // //     printf("Failed to find player field 'h'.\n");
        // //     return;
        // // }
        // jobject plr = env->GetObjectField(minecraftInstance, plrField);
        
        // if(plr == NULL){
        //     printf("Player object is null, are you loaded in a game yet?");
        //     return;
        // }

        // jclass plrClass = env->GetObjectClass(plr);
        
        // // Calling player.jump();
        // jmethodID jumpMethod = env->GetMethodID(plrClass, "bF", "()V");
        // // if (jumpMethod == NULL) {
        // //     printf("Failed to find jump method 'bf'.\n");
        // //     return;
        // // }
        // env->CallVoidMethod(plr, jumpMethod);
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
        return TRUE;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

