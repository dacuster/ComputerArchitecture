; Assignment 4.2
; Nick DaCosta

.386												; Enable the instruction set (386, 486, 586, 686)
.MODEL FLAT, stdcall								; Linear model type (x64 only has 1 so it doesn't need to be chosen) stdcall is the calling convention
.STACK 4096											; Setup the specific amount of memory stack we want allocated for the program 4096 for x86

ExitProcess PROTO, dwExitCode:DWORD					; Create the exit process definition.

.DATA												; Begin global static variables
arrayEarnedGrade DWORD 25, 89, 49, 80				; Initialized array of earned grades.
earnedArrayLength EQU ($ - arrayEarnedGrade)		; Calculate the length of the earned grades array.
arrayPossibleGrade DWORD 30, 100, 50, 150			; Initialized array of possible grades.
possibleArrayLength EQU ($ - arrayPossibleGrade)	; Calculate the length of the possible grades array.
sumEarned DWORD 0									; Initialized sumEarned variable.
sumPossible DWORD 0									; Initialized sumPossible variable.
resultGrade DWORD 0									; Initialized resultGrade variable.

.CODE												; Begin the code section.
_main PROC											; Begin the main function.
	xor eax, eax									; Clear eax to 0.
	xor edx, edx									; Start index of array as 0. (Clear to 0)
	mov eax, [arrayEarnedGrade + edx * 4]			; Move the current arrayEarnedGrade index value to eax.
	add sumEarned, eax								; Add the value in eax to sumEarned.
	inc edx											; Increment the arrayEarnedGrade index that is stored in edx.
	mov eax, [arrayEarnedGrade + edx * 4]			; Move the current arrayEarnedGrade index value to eax.
	add sumEarned, eax								; Add the value in eax to sumEarned.
	inc edx											; Increment the arrayEarnedGrade index that is stored in edx.
	mov eax, [arrayEarnedGrade + edx * 4]			; Move the current arrayEarnedGrade index value to eax.
	add sumEarned, eax								; Add the value in eax to sumEarned.
	inc edx											; Increment the arrayEarnedGrade index that is stored in edx.
	mov eax, [arrayEarnedGrade + edx * 4]			; Move the current arrayEarnedGrade index value to eax.
	add sumEarned, eax								; Add the value in eax to sumEarned.

	xor eax, eax									; Clear eax to 0.
	xor edx, edx									; Start index of array as 0. (Clear to 0)
	mov eax, [arrayPossibleGrade + edx * 4]			; Move the current arrayPossibleGrade index value to eax.
	add sumPossible, eax							; Add the value in eax to sumPossible.
	inc edx											; Increment the arrayPossibleGrade index that is stored in edx.
	mov eax, [arrayPossibleGrade + edx * 4]			; Move the current arrayPossibleGrade index value to eax.
	add sumPossible, eax							; Add the value in eax to sumPossible.
	inc edx											; Increment the arrayPossibleGrade index that is stored in edx.
	mov eax, [arrayPossibleGrade + edx * 4]			; Move the current arrayPossibleGrade index value to eax.
	add sumPossible, eax							; Add the value in eax to sumPossible.
	inc edx											; Increment the arrayPossibleGrade index that is stored in edx.
	mov eax, [arrayPossibleGrade + edx * 4]			; Move the current arrayPossibleGrade index value to eax.
	add sumPossible, eax							; Add the value in eax to sumPossible.

	mov ebx, 100									; Move 100 (multiplier) to ebx.
	mov eax, sumEarned								; Move sumEarned (multiplicand) to eax.
	mul ebx											; Multiply eax by ebx.
	mov sumEarned, eax								; Move value result in eax to sumEarned.

	xor edx, edx									; Clear edx to 0. (dividend upper bits).
	mov eax, sumEarned								; Move the value of sumEarned to eax (dividend lower bits).
	mov ecx, sumPossible							; Move the value of sumPossible to ecx (divisor).
	div ecx											; Divide edx:eax by ecx (result stored as quotient in eax and remainder in edx).

	mov resultGrade, eax							; Store the quotient value of eax in resultGrade.

	INVOKE ExitProcess, 0							; Call exit process to end function.
_main ENDP											; End the main function.
END													; End the program.