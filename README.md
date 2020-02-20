# APIHook
```X86 API Hook```

This is a very simple C++ class for X86 API Hooking.

Code Example: 
```

#include "cHook.h"

BYTE bPatch[6];

int WINAPI MessageBoxAHook(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {

    cHook::UnHookFunction("user32.dll", "MessageBoxA", bPatch);

    int iResult =  MessageBoxA(NULL, "Hooked", "Hooked", MB_OK | MB_ICONERROR);

	cHook::HookFunction("user32.dll", "MessageBoxA", MessageBoxAHook, bPatch);
	
	return iResult;

}

int main()
{
   

    cHook::HookFunction("user32.dll", "MessageBoxA", MessageBoxAHook, bPatch);

    Sleep(500);

    MessageBoxA(NULL, "Hook Me", "Hook", MB_OK);

    cHook::UnHookFunction("user32.dll", "MessageBoxA", bPatch);

    return EXIT_SUCCESS;
}


```
