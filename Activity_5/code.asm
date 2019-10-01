; Program 5.2
; Looping - MASM (32-bit)
; Copyright (c) 2019 Hall & Slonka

.386
.MODEL FLAT, stdcall
.STACK 4096
ExitProcess PROTO, dwExitCode:DWORD

.data
value DWORD ?
counter DWORD ?

.code
_main PROC

mov value, 0
mov ecx, 2
outer:
	mov counter, ecx
	mov ecx, 3
	inner:
		inc value
		loop inner
		mov ecx, counter
	loop outer

INVOKE ExitProcess, 0
_main ENDP
END