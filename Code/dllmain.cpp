#pragma once
#include <Windows.h>
#include "Script.h"
#include "keyboard.h" // TEMP

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        scriptRegister(hModule, ScriptMain);
        keyboardHandlerRegister(OnKeyboardMessage); // TEMP
        break;
    case DLL_PROCESS_DETACH:
        scriptUnregister(hModule);
        keyboardHandlerUnregister(OnKeyboardMessage); // TEMP
        break;
    }
    return TRUE;
}

