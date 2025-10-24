#include <Windows.h>
#include "Java.h"
#include "Cheat.h"

void initialize() {
    jsize count;
    if(JNI_GetCreatedJavaVMs(&cheeto.vm, 1, &count) != JNI_OK || count == 0) return;

    jint rest = cheeto.vm->GetEnv((void**)&cheeto.environment, JNI_VERSION_1_6);
    if (rest == JNI_EDETACHED)
        rest = cheeto.vm->AttachCurrentThread((void**)&cheeto.environment, nullptr);

    if (cheeto.environment != nullptr);
        modules();
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)initialize, 0, 0, 0)
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

