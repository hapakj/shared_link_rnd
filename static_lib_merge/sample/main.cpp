#include "sub_lib_a.h"
#include "sub_lib_b.h"
#include "main_lib.h"

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

