#pragma once

int ntacc_retrieve_syscall_id(const char* func);
extern int ntacc_called;

// functions lol

extern "C" void* ntacc_createthreadex(PHANDLE ThreadHandle, ACCESS_MASK DesiredAccess, PVOID ObjectAttributes, HANDLE ProcessHandle, PVOID StartRoutine, PVOID Argument, ULONG CreateFlags, SIZE_T ZeroBits, SIZE_T StackSize, SIZE_T MaximumStackSize, PVOID AttributeList, BYTE syscall_id, BOOL debug);
