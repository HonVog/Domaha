#pragma once
#include <iostream>

using namespace std;

class Pet
{
public:
	Pet(std::string name, bool itFlies) : _name{ name }, _itFlies{ itFlies }{}

	virtual void _Print() {
		cout << "Pet Name : " << _name 
			<< ((_itFlies) ? " ; it's a bird \n" : " ; it's not a bird \n");
	}
protected:
	std::string _name;
	bool _itFlies;

	virtual ~Pet() {}
};

