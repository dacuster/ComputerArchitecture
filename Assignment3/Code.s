# Assignment 3.1
# Defining variables

.data					# Begin defining initialized variables.
.long sum $0x10000		# Sum variable to hold the initializer 0x10000.
message: .ascii "Welcome to Assembly programming.\nYour grade will be randomly assigned\nby the Intel 8086 processor!\0"	# Message variable to hold the text with line breaks.

.bss					# Begin defining uninitialized veriables.
.lcomm input, 1			# Input variable that is able to hold the values 0-255 (byte).

.text					# Begin code section.
.globl _main			# Initialize main as a function.
_main:					# Begin main.

movb $200, input		# Assign the decimal value 200 to input.

int $0x80				# Call the exit process.
.end					# End main.