#include "lib_a.h"
#include "lib_b.h"
#include "lib_c.h"

#include <iostream>

int main(int argc, char ** argv)
{
	LibA::GetInstance().Print();
	LibB::GetInstance().Print();
	LibC::GetInstance().Print();

	std::cout << "Sample: " << std::endl;
	std::cout << "LibA instance: " << &LibA::GetInstance() << std::endl;
	std::cout << "LibB instance: " << &LibB::GetInstance() << std::endl;
	std::cout << "LibC instance: " << &LibC::GetInstance() << std::endl << std::endl;

	return 0;
}

