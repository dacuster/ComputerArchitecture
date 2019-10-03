; code.asm
.386
.MODEL FLAT, stdcall
.STACK 4096
.CODE
asmMain PROC C
	int	3		; system interupt to debug in obj files
	xor eax, eax
	mov eax, 0
	inc eax

	ret
asmMain ENDP
END