#include <windows.h>
#include <iostream>

#include "ntapartment.h"

extern "C" void* ntacc_createthreadex(PHANDLE ThreadHandle, ACCESS_MASK DesiredAccess, PVOID ObjectAttributes, HANDLE ProcessHandle, PVOID StartRoutine, PVOID Argument, ULONG CreateFlags, SIZE_T ZeroBits, SIZE_T StackSize, SIZE_T MaximumStackSize, PVOID AttributeList, BYTE syscall_id, BOOL debug)
{
    BYTE stubby[] = {
    0x4C, 0x8B, 0xD1,                  
    0xB8, syscall_id, 0x00, 0x00, 0x00, // move syscall id to eax thx
    0x0F, 0x05,                         // syscall
    0xC3                                // i love cartiiiiiiiiii :3
    };

    if (debug == true){
        std::cout << "\n\033[96m[DEBUG]\033[0m calling ";
        std::cout << static_cast<int>(syscall_id);
    }

    void* vrovro420 = VirtualAlloc(NULL, sizeof(stubby), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!vrovro420) return nullptr; // is this good practise idk copilot thinks it is

    memcpy(vrovro420, stubby, sizeof(stubby));

    auto fn = (void* (*)(PHANDLE, ACCESS_MASK, PVOID, HANDLE, PVOID, PVOID, ULONG, SIZE_T, SIZE_T, SIZE_T, PVOID))
    vrovro420;


    void* result = fn(ThreadHandle, DesiredAccess, ObjectAttributes, ProcessHandle, StartRoutine, Argument, CreateFlags, ZeroBits, StackSize, MaximumStackSize, AttributeList);

    VirtualFree(vrovro420, 0, MEM_RELEASE);

    return result;
};
