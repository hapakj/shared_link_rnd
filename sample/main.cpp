#include "static_a.h"
#include "static_b.h"
#include "shared.h"

#include <iostream>

int main(int argc, char ** argv)
{
	std::cout << "call static from main:" << std::endl;
	static_a();
	static_b();
	
	std::cout << "call shared:" << std::endl;
	shared();
	
	return 0;
}

