# coldcaller-ntapartment
**This repo is like only half written so there's a lot of unused crap**
--
super simple and crudely written bypass for usermode winapi hooks
originally made for roblox's hyperion
# how it works
ntacc_retrieve_syscall_id gets a syscall id from a function via ntdll stub
the returned BYTE can be input into a function like the function defined in ntacc-shellcode-build.cpp, shellcodes are built, then ran.

I'm not entirely sure if this works because I've done a lack of testing

If you're pasting this (which I doubt), I'd like credit
