; Assignment 3.3
; Syntax Translation - GAS, Clang/LLVM on Linux (32-bit)
; Copyright (c) 2017 Hall & Slonka

.386						;.data
.MODEL FLAT, stdcall
.STACK 4096

ExitProcess PROTO, dwExitCode:DWORD

.DATA						;.bss
letter BYTE ?				;.lcomm letter, 1
r DWORD ?					;.lcomm r, 4
s DWORD ?					;.lcomm s, 4
t DWORD ?					;.lcomm t, 4
x WORD ?					;.lcomm x, 2
y WORD ?					;.lcomm y, 2
z WORD ?					;.lcomm z, 2

.CODE						;.text
							;.globl _main
_main PROC					;_main:

	mov letter, 77h			;movb $0x77, letter
	mov r, 5h				;movl $0x5, r
	mov s, 2h				;movl $0x2, s
	mov x, 0ah				;movw $0xa, x
	mov y, 4h				;movw $0x4, y

	mov ax, x				;movw x, %ax
	add ax, y				;addw y, %ax
	mov z, ax				;movw %ax, z

	mov ax, x				;movw x, %ax
	sub ax, y				;subw y, %ax
	mov z, ax				;movw %ax, z

	mov edx, 0h				;movl $0x0, %edx
	mov eax, r				;movl r, %eax
	mov ecx, s				;movl s, %ecx
	div ecx					;divl %ecx
	mov t, eax				;movl %eax, t

	mov edx, 0h				;movl $0x0, %edx
	mov eax, r				;movl r, %eax
	mov ecx, s				;movl s, %ecx
	div ecx					;divl %ecx
	mov t, edx				;movl %edx, t

	mov eax, 1				;movl $1, %eax
	mov ebx, 0				;movl $0, %ebx

	INVOKE ExitProcess, 0	;int $0x80
_main ENDP					;.end
END						