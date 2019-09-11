; First program

.386 ; Enable the instruction set (386, 486, 586, 686)
.MODEL FLAT, stdcall ; linear model type (x64 only has 1 so it doesn't need to be chosen) stdcall is the calling convention
.STACK 4096 ; setup the specific amount of memory stack we want allocated for the program 4096 for x86

ExitProcess PROTO, dwExitCode:DWORD

.DATA ; global static variables
num DWORD 80 ; initialized data
sum DWORD ? ; uninitialized data

.CODE ; TEXT and CODE mean the same thing across architectures.
_main PROC
	mov eax, num ; move num to eax register
	add eax, 20
	mov sum, eax

	INVOKE ExitProcess, 0
_main ENDP
END
