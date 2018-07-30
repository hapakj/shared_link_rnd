#include "lib_b.h"

#include <iostream>

#ifndef INLINED
LibB& LibB::GetInstance()
{
	static LibB instance;
	return instance;
}
#endif

void LibB::Print()
{
	std::cout << "LibB: " << std::endl;
	std::cout << "LibA instance: " << &LibA::GetInstance() << std::endl;
	std::cout << "LibB instance: " << &LibB::GetInstance() << std::endl << std::endl;
}

