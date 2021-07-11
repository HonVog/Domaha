#pragma once
#include <iostream>

class Abstrac
{	
public:
	virtual ~Abstrac() {
		std::cout << "\n~Abstrac() : "<< std::endl;
	}

	virtual void Print() = 0;
	virtual void Print( int ) = 0;
protected:
	int size; // размер
};

