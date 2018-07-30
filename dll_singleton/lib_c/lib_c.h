#pragma once
#include "lib_a.h"

#include <iostream>

class LibC
{
public:

#ifndef INLINED
	static LibC& GetInstance();
#else
	static LibC& GetInstance()
	{
		static LibC instance;
		return instance;
	}
#endif

	void Print();
};

