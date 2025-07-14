#include <iostream>
#include <windows.h>
#define WIN32_LEAN_AND_MEAN

#include "ntapartment.h"

using namespace std;

int ntacc_called = 0;

int ntacc_retrieve_syscall_id(const char* func)
{

    cout << "\033[94m>\033[0m retrieving syscall-id > ";
    cout << func;

    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (!hNtdll) return 0;

    BYTE* addr = (BYTE*)GetProcAddress(hNtdll, func);
    if (!addr) return 0;

    cout << " > \033[95m";
    cout << static_cast<int>(addr[4]);
    cout << "\n\033[0m";

    ntacc_called++;

    return addr[4];
};
