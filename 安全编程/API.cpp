#include <stdio.h>
#include <Windows.h>

int main()
{
    __asm
    {
        CLD
        push 0x7596F500
        push // ExitProcess
        push                                                                               // LoadLibraryA
        mov esi,esp
        lea dei,[esi-0xc]
        
        xor ebx,ebx 
        mov bh,0x04
        sub esp,ebx
       
    }
}