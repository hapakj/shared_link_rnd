#pragma once

#include <iostream>

class LibA
{
public:

#ifndef INLINED
	static LibA& GetInstance();
#else
	static LibA& GetInstance()
	{
		static LibA instance;
		return instance;
	}
#endif

	void Print();
};

