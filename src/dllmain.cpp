#include <Windows.h>
#include <iostream>
#include "sdk/minecraft/minecraft.h"
#include "sdk/classes/classes.h"

void initialize(HMODULE module) {
    FILE* output_buffer = nullptr;
    AllocConsole();
    freopen_s(&output_buffer, "CONOUT$", "w", stdout);

    jvm::load();
    classes::load();

    while (!GetAsyncKeyState(VK_DELETE)) {
        std::cout << "Instance Found: " << c_minecraft::get_minecraft().cached_object << ".\n";
        Sleep(1000);
    }

    if (output_buffer) fclose(output_buffer);
    FreeConsole();
    FreeLibraryAndExitThread(module, 0ul);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:{
        HANDLE thread_handler = CreateThread(nullptr, 0ull, reinterpret_cast<LPTHREAD_START_ROUTINE>(initialize), hModule, 0ull, nullptr);
        if (thread_handler && thread_handler != INVALID_HANDLE_VALUE) CloseHandle(thread_handler);
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

