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
	float PI;
	float userInput1 = 0.0f;
	float userInput2 = 0.0f;
	float result1 = 0.0f;
	float result2 = 0.0f;
	float result3 = 0.0f;

	// Ask for user input.
	std::cout << "Enter a floating point number: ";
	std::cin >> userInput1;
	std::cout << "Enter a second floating point number: ";
	std::cin >> userInput2;

	// Title for FPU operations.
	std::cout << std::endl << "FPU Instructions" << std::endl;
	// x87 Floating-Point.
	__asm
	{
		finit
		fldpi // Load PI into the FPU stack.
		fst PI // Set the PI variable to PI.
		fmul userInput1 // Multiply userInput1 by the value on the top of the FPU stack.
		fsub userInput2 //  Subtract the value on the top of the FPU stack by userInput2.
		fstp result1 // Pop the top of the FPU stack and place the value in result1.
	};
	// Print the result from the FPU operations.
	std::cout << "PI * " << userInput1 << " - " << userInput2 << " = " << result1 << std::endl;

	// Title for SSE operations.
	std::cout << std::endl << "SSE Instructions" << std::endl;
	// SSE Scalar.
	__asm
	{
		movss xmm0, PI // Move PI to xmm0.
		mulss xmm0, userInput1 // Multiply userInput1 by xmm0(PI) and store it in xmm0.
		subss xmm0, userInput2 // Subtract userInput2 from the value in xmm0 and store in xmm0.
		movss result2, xmm0 // Move the value in xmm0 to result2.
	};

	// Print the result from the SSE operations.
	std::cout << "PI * " << userInput1 << " - " << userInput2 << " = " << result2 << std::endl;

	// Title for AVX operations.
	std::cout << std::endl << "AVX Instructions" << std::endl;
	__asm
	{

	};

	// Print the result from the AVX operations.
	std::cout << result3 << std::endl;

	return 0;
}