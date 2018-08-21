#include "main_lib.h"
#include "sub_lib_a.h"
#include "sub_lib_b.h"

#include <iostream>

void shared()
{
	static_a();
	static_b();
	std::cout << "shared" << std::endl;
}

