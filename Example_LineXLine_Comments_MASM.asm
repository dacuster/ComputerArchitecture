; Program 3.2
; Working Example - MASM (32-bit)
; Copyright (c) 2017 Hall & Slonka

.386                                ; Enable x86 instruction set
.MODEL FLAT, stdcall                ; Flat memory model, processor's
                                    ; protected mode (all instructions
                                    ; and features available)
.STACK 4096                         ; Runtime stack size
                                    ; (same as memory page size)
ExitProcess PROTO, dwExitCode:DWORD ; Prototype for ExitProcess method


.data                               ; Section for variable definitions

decimalLiteral    BYTE 31           ; Variable storing 31
hexLiteral        DWORD 0Fh         ; Variable storing F (15 in decimal)
charLiteral       BYTE 'A'          ; Variable storing 65 in decimal
unInitVariable    DWORD ?           ; 4-byte uninitialized variable

; Variable containing a string that has a line break and is null-terminated
stringLiteral     BYTE "This is a string that",0dh,0ah
                  BYTE "has a line break in it.",0

; Variable that calculates the value of an expression to determine the
; length, in bytes, of the variable "stringLiteral" by subtracting the
; starting memory address of the variable from the current memory address
lenString         EQU ($ - stringLiteral)

.code                             ; Section for instructions
_main PROC                        ; Start of "_main" procedure

; Label and instruction on
; the same line below
partOne: mov eax, 10              ; Assign 10 to the eax register
add eax, hexLiteral               ; Add the value in hexLiteral to
                                  ; the contents of the eax register
                                  ; and store the result in eax

partTwo:                          ; Label on its own line
inc eax                           ; Increment the value in eax

INVOKE ExitProcess, 0             ; Call the ExitProcess method
_main ENDP                        ; End of "_main" procedure
END                               ; End assembling