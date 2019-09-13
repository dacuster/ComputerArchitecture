; Assignment 3.3
; Syntax Translation - GAS, Clang/LLVM on Linux (32-bit)
; Copyright (c) 2017 Hall & Slonka

.386				;.data
.MODEL FLAT, stdcall
.STACK 4096

ExitProcess PROTO, dwExitCode:DWORD

.DATA					;.bss
letter BYTE ?			;.lcomm letter, 1
r DWORD ?				;.lcomm r, 4
s DWORD ?				;.lcomm s, 4
t DWORD ?				;.lcomm t, 4
x WORD ?				;.lcomm x, 2
y WORD ?				;.lcomm y, 2
z WORD ?				;.lcomm z, 2

.CODE					;.text
						;.globl _main
_main PROC				;_main:

	mov letter, 0x77	;movb $0x77, letter
	MOV r, 0x5l			;movl $0x5, r
	MOV s, 0x2			;movl $0x2, s
	MOV x, 0xa			;movw $0xa, x
	MOV y, 0x4			;movw $0x4, y

	MOV ax, x			;movw x, %ax
	ADD ax, y			;addw y, %ax
	MOV z, ax			;movw %ax, z

	MOV ax, x			;movw x, %ax
	SUB ax, y			;subw y, %ax
	MOV z, ax			;movw %ax, z

	MOV edx, 0x0h		;movl $0x0, %edx
	MOV eax, r			;movl r, %eax
	MOV ecx, s			;movl s, %ecx
	DIV ecx				;divl %ecx
	MOV t, eax			;movl %eax, t

	MOV edx, 0x0h		;movl $0x0, %edx
	MOV eax, r			;movl r, %eax
	MOV ecx, s			;movl s, %ecx
	DIV ecx				;divl %ecx
	MOV t, edx			;movl %edx, t

	MOV eax, 1			;movl $1, %eax
	MOV ebx, 0			;movl $0, %ebx
	INT 0x80			;int $0x80

	INVOKE ExitProcess, 0
_main ENDP
END						;.end