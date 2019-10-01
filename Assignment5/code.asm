; Assignment 5 Alternative 2
; Nick DaCosta

.386												; Enable the instruction set (386, 486, 586, 686)
.MODEL FLAT, stdcall								; Linear model type (x64 only has 1 so it doesn't need to be chosen) stdcall is the calling convention
.STACK 4096											; Setup the specific amount of memory stack we want allocated for the program 4096 for x86

ExitProcess PROTO, dwExitCode:DWORD					; Create the exit process definition.

.DATA												; Begin global static variables
; Test pins
; Test range of each digit.
;pinArray DWORD 1, 2, 8, 4							; Low  first  pin
;pinArray DWORD 8, 2, 8, 4							; High first  pin
;pinArray DWORD 5, 0, 8, 4							; Low  second pin
;pinArray DWORD 5, 6, 8, 4							; High second pin
;pinArray DWORD 5, 2, 3, 4							; Low  third  pin
;pinArray DWORD 5, 2, 10, 4							; High third  pin
;pinArray DWORD 5, 2, 8, 1							; Low  fourth pin
;pinArray DWORD 5, 2, 8, 9							; High fourth pin

; Test signed values.
;pinArray DWORD -5, 2, 8, 9							; Signed first  pin
;pinArray DWORD 5, -2, 8, 9							; Signed second pin
;pinArray DWORD 5, 2, -8, 9							; Signed third  pin
;pinArray DWORD 5, 2, 8, -9							; Signed fourth pin

; Test exact low and high range value pins.
;pinArray DWORD 3, 1, 7, 2							; Exact lower  pin range.
;pinArray DWORD 6, 4, 9, 5							; Exact higher pin range.

; Some valid pins.
pinArray DWORD 4, 2, 8, 3							; Random valid pin
;pinArray DWORD 4, 3, 8, 4							; Random valid pin
;pinArray DWORD 5, 2, 9, 2							; Random valid pin

validPinMinArray DWORD 3, 1, 7, 2					; Valid minimums for each pin.
validPinMaxArray DWORD 6, 4, 9, 5					; Valid maximums for each pin.

.CODE												; Begin the code section.
_main PROC											; Begin the main function.

xor eax, eax										; Clear eax to 0 for final pin validity check.
xor edx, edx										; Clear edx to 0 for array index tracking.
mov ecx, 4											; Set initial loop value of 4.

pinLoop:											; Pin value check loop.
	mov ebx, [pinArray + edx * 4]					; Set ebx to the value of the current index of pinArray.
	mov esi, [validPinMinArray + edx * 4]			; Set esi to the value of the current index of validPinMinArray.
	cmp ebx, esi									; Compare ebx with esi;
	jl incorrectPin									; Jump to incorrectPin if the value of ebx is lower than esi.
	mov esi, [validPinMaxArray + edx * 4]			; Set esi to the value of the current index of validPinMaxArray.
	cmp ebx, esi									; Compare ebx with esi.
	jg incorrectPin									; Jump to incorrectPin if the value of ebx is greater than esi.
	inc edx											; Increment edx for the array counter.
	loop pinLoop									; Go back to the beginning of pinLoop.
	jmp correctPin									; Unconditional jump to correctPin.


incorrectPin:										; Incorrect pin label.
	mov eax, 0										; Set eax to 0 to indicate a false pin.
	jmp done										; Unconditional jump to done.

correctPin:											; Correct pin label.	
	mov eax, 1										; Set eax to 1 to indicate a true pin.

done:												; Done label to jump over correctPin.

	INVOKE ExitProcess, 0							; Call exit process to end function.
_main ENDP											; End the main function.
END													; End the program.