#pragma once
#include <Windows.h>

class cHook
{
	
public:

	static DWORD HookFunction(LPCSTR pszModule, LPCSTR pszFuncName, LPVOID lpFunction, LPBYTE lpBackup);
	static BOOL UnHookFunction(LPCSTR pszModule, LPCSTR pszFuncName, LPBYTE lpBackup);

};
