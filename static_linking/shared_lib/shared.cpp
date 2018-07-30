#include "shared.h"
#include "static_a.h"
#include "static_b.h"

#include <iostream>

void shared()
{
	static_a();
	static_b();
	std::cout << "shared" << std::endl;
}

