// Program 9.1
// Simple Inline Assembly - Visual C++ (32-bit)
// Copyright (c) 2017 Hall & Slonka

#include <iostream>

int main()
{

	int var1 = 1234;
	int var2;

	__asm
	{
		mov eax, var1
		add eax, 2
		mov var2, eax
	}

	std::cout << var2 << std::endl;

	return 0;
}