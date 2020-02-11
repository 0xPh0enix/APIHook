/*
	Coded by 0xPh0enix
*/

#include "cHook.h"


DWORD cHook::HookFunction(LPCSTR pszModule, LPCSTR pszFuncName, LPVOID lpFunction, LPBYTE lpBackup){

	HMODULE hModule = GetModuleHandleA(pszModule);

	if (!hModule)
		return 0;

	DWORD dwAddr = (DWORD)GetProcAddress(hModule, pszFuncName);

	BYTE bJMP[6] = { 0xe9, 0x00, 0x00, 0x00, 0x00, 0xc3 };

	ReadProcessMemory(GetCurrentProcess(), (LPVOID)dwAddr, lpBackup, 6, 0);

	DWORD dwCalc = ((DWORD)lpFunction - dwAddr - 5);	

	memcpy(&bJMP[1], &dwCalc, 4);

	WriteProcessMemory(GetCurrentProcess(), (LPVOID)dwAddr, bJMP, 6, 0);

	return dwAddr;
}

BOOL cHook::UnHookFunction(LPCSTR lpModule, LPCSTR lpFuncName, unsigned char* lpBackup)
{
	HMODULE hModule = GetModuleHandleA(lpModule);

	if (!hModule)
		return FALSE;

	DWORD dwAddr = (DWORD)GetProcAddress(hModule, lpFuncName);

	if (WriteProcessMemory(GetCurrentProcess(), (LPVOID)dwAddr, lpBackup, 6, 0))
		return TRUE;

	return FALSE;
}