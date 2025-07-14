#include <iostream>
#include <windows.h>
#define WIN32_LEAN_AND_MEAN

HMODULE ntdll = LoadLibraryA("ntdll.dll");

#include "ntapartment/ntapartment.h"
#include "coldcaller-main.h"

using namespace std;

const char* func1 = "NtCreateThreadEx";
const char* func2 = "NtAllocateVirtualMemoryEx";
const char* func3 = "NtProtectVirtualMemory";
const char* func4 = "NtWriteVirtualMemory";
const char* func5 = "NtOpenProcess";
const char* func_test = "NtCreateFile";

BYTE sc_id1;
BYTE sc_id2;
BYTE sc_id3;
BYTE sc_id4;
BYTE sc_id5;
BYTE sc_id_test;

int cc_init()
{
    cout << "\033[94m+\033[0m coldcaller init...\n \n";

    //define and get ids of blocked funcs

    sc_id1 = ntacc_retrieve_syscall_id(func1);
    sc_id2 = ntacc_retrieve_syscall_id(func2);
    sc_id3 = ntacc_retrieve_syscall_id(func3);
    sc_id4 = ntacc_retrieve_syscall_id(func4);
    sc_id5 = ntacc_retrieve_syscall_id(func5);
    sc_id_test = ntacc_retrieve_syscall_id(func_test);

    cout << "\n";
    cout << "\033[94m+\033[0m all functions initialized! ";
    cout << ntacc_called;
    return 0;
}


