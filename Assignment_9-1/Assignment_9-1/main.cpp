// Program 9.2
// Floating-Point Inline Assembly - Visual C++ (32-bit)
// Copyright (c) 2017 Hall & Slonka


// Get 2 floats from user
// Perform 3 ops in inline using user params and fpu/sse/avx instructions
// After each computation store the value in a variable
// Print the results to the console in C++
// Encouraged to use PI and FSQRT, SQRTSS, SQRTSD

#include <iostream>

int main()
{
	float userInput1 = 0.0f;
	float userInput2 = 0.0f;
	float result1 = 0.0f;
	float result2 = 0.0f;
	float result3 = 0.0f;

	std::cout << "Enter a floating point number: ";
	std::cin >> userInput1;
	std::cout << std::endl << "Enter a second floating point number: ";
	std::cin >> userInput2;

	// x87 floating-point.
	__asm
	{
		finit
		fldpi // Load PI into the FPU stack.
		fmul userInput1 // Multiply userInput1 by the value on the top of the FPU stack.
		fsub userInput2 //  Subtract the value on the top of the FPU stack by userInput2.
		fstp result1 // Pop the top of the FPU stack and place the value in result1.
	};

	std::cout << "PI * " << userInput1 << " - " << userInput2 << " = " << result1 << std::endl;

	// SSE Scalar.
	__asm
	{
		movss xmm0, userInput2
		addss xmm0, userInput1
		movss userInput1, xmm0
	};

	__asm
	{

	};

	std::cout << userInput1 << std::endl;

	return 0;
}