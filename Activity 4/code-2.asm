.386
.MODEL FLAT, stdcall
.STACK 4069
ExitProcess PROTO, dwExitCode:DWORD

.data
; Complete equality test.
stringOne BYTE "Try harder", 0
lengthStringOne EQU ($ - stringOne)
stringTwo BYTE "Try harder", 0
lengthStringTwo EQU ($ - stringTwo)
partialEqualityFlag DWORD 0					; Set to 1(true) to check for partial string equality. 0(false)

;; Partial equality test.
;stringOne BYTE "Try harder still", 0
;lengthStringOne EQU ($ - stringOne)
;stringTwo BYTE "Try harder", 0
;lengthStringTwo EQU ($ - stringTwo)
;partialEqualityFlag DWORD 1				; Set to 1(true) to check for partial string equality. 0(false)

;; Inequality test.
;stringOne BYTE "Try harder", 0
;lengthStringOne EQU ($ - stringOne)
;stringTwo BYTE "Try harder still", 0
;lengthStringTwo EQU ($ - stringTwo)
;partialEqualityFlag DWORD 0				; Set to 1(true) to check for partial string equality. 0(false)

equalString DWORD 0							; Set up equal string check and initialize it to 0(false).

.code
_main PROC

	; Check if partial equality test
	; should be done.
	; (String lengths don't matter)
	xor eax, eax							; Clear eax to 0.
	cmp eax, partialEqualityFlag			; Compare partial equality flag with 0(false).
	jne set_strings							; Jump to set_strings if partialEqualityFlag was set to 1(true) (or anything other than 0).

	; Lengths need to be exactly the
	; same if they are the exact
	; same strings.
	mov eax, lengthStringOne				; Move the value (length of stringOne) to eax.
	cmp eax, lengthStringTwo				; Compare the value (length of stringTwo) to eax.
	jne done								; Lengths are not the same. Jump to done.
	
	; Set registers with the strings
	; based on their lengths. Prevents
	; check past bounds.
	set_strings:
		mov ecx, lengthStringOne			; Move stringLength1 to ecx to use as a loop counter length. stringOne is assumed shorter.
		cmp eax, lengthStringTwo			; Compare lengthStringTwo to eax(lengthStringOne).
		jl	compare_strings					; lengthStringOne is shorter than lengthStringTwo. Jump to compare_strings
		mov ecx, lengthStringTwo			; Move stringLength2 to ecx to use as a loop counter length. stringTwo is shorter.
	
	; Compare the two strings.
	compare_strings:
		lea esi, stringOne					; Load the memory address of stringOne to esi.
		lea edi, stringTwo					; Load the memory address of stringTwo to edi.
		cld									; Clear the direction flag. Read strings left-to-right.
		repe cmpsb							; Compare character by character as long as each character is equal in each iteration.
		jnz done							; Character mismatch. Jump to done.

	mov equalString, 1						; Strings are the same. Set the equalString variable to 1(true).
	
	; End the program
	done:
	INVOKE ExitProcess, 0
_main ENDP
END