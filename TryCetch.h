#pragma once
#include "Abstrac.h"
#include <iostream>

class TryCetch : public Abstrac {
public:
	TryCetch () { size = 0; }
	TryCetch (int i) { size = i; }

	int Chek(const Abstrac* info) {
		try {
			if (size == 0)
				throw size;
			return size;
		}
		catch (int i){
			std::cout << "The length is zero" << std::endl;
			return i;
		}	
	}



};

