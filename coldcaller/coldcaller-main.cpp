#include <iostream>
#include <windows.h>
#define WIN32_LEAN_AND_MEAN

#include "ntapartment/ntapartment.h"
#include "coldcaller-main.h"

using namespace std;

const char* func1 = "NtCreateThreadEx";
const char* func_test = "NtCreateFile";

BYTE sc_id1;
BYTE sc_id_test;

int cc_init()
{
    cout << "\033[94m+\033[0m coldcaller init...\n \n";

    //define and get ids of blocked funcs

    sc_id1 = ntacc_retrieve_syscall_id(func1);
    sc_id_test = ntacc_retrieve_syscall_id(func_test);

    cout << "\n";
    cout << "\033[94m+\033[0m all functions initialized! ";
    cout << ntacc_called;
    return 0;
}


