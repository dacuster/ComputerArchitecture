; Program 6.1
; Sum Program - MASM (32-bit)
; Copyright (c) 2017 Hall & Slonka

.386
.MODEL FLAT, C
ExitProcess PROTO stdcall, dwExitCode:DWORD

.data
num1 DWORD 2
num2 DWORD 4

.code
_main PROC

mov eax, 10
dec eax
mov ebx, 5

push num2
push num1
call _sum
add esp, 8 ; Add 8 bytes to esp to increase stack size to dereference 2 parameters passed to function.

add eax, ebx
dec eax

INVOKE ExitProcess, 0
_main ENDP

_sum PROC
push ebp;Save caller base frame pointer
mov ebp, esp ; push the current memory location(ebp) of this function
push ebx	; local variable (just example. not needed)
mov ebx, [ebp + 8]	; access first variable passed to function. jump past 2 memory location (previous functions stack location and return type location)
mov eax, [ebp + 12]
add eax, ebx ; eax is guaranteed to save when going back to caller function.
pop ebx ; put the value of ebx back from the stack
pop ebp ; point back to the caller stack pointer
ret
_sum ENDP

END