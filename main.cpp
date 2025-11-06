#include "main.h"
#include "functions.h"
#include "modules.h"

void client_main(HMODULE hModule){
    // Initialize modules here

    Fly *fly_mod = new Fly();
    fly_mod->toggle();
    mods.push_back(fly_mod);

    while(true){
        //plrJump(env);
        call_event("Client-tick", "");
        Sleep(50);

        if(GetAsyncKeyState(VK_DELETE)){
            break;
        }
    }

    // Self-destruct, free any memory allocated
    printf("Self-destructing\n");
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return;
}