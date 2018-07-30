#pragma once
#include "lib_a.h"

#include <iostream>

class LibB
{
public:

#ifndef INLINED
	static LibB& GetInstance();
#else
	static LibB& GetInstance()
	{
		static LibB instance;
		return instance;
	}
#endif

	void Print();
};

