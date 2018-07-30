#include "lib_c.h"

#include <iostream>

#ifndef INLINED
LibC& LibC::GetInstance()
{
	static LibC instance;
	return instance;
}
#endif

void LibC::Print()
{
	std::cout << "LibB: " << std::endl;
	std::cout << "LibA instance: " << &LibA::GetInstance() << std::endl;
	std::cout << "LibC instance: " << &LibC::GetInstance() << std::endl << std::endl;
}

