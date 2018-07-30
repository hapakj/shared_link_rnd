#include "lib_a.h"

#include <iostream>

#ifndef INLINED
LibA& LibA::GetInstance()
{
	static LibA instance;
	return instance;
}
#endif


void LibA::Print()
{
	std::cout << "LibA:" << std::endl;
	std::cout << "LibA instance: " << &GetInstance() << std::endl << std::endl;
}
