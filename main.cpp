#include "main.h"
#include "functions.h"

void client_main(HMODULE hModule){
    while(true){
        mc_thePlayer_jump(env);
        Sleep(50);

        if(GetAsyncKeyState(VK_END)){
            break;
        }
    }

    // Self-destruct, free any memory allocated
    printf("Self-destructing\n");
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return;
}