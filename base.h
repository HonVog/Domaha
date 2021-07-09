#pragma once

#include <iostream>
#include <string>
#include <Windows.h>


template <class T1, class T2>
class base {
public:
	T1 value1; 
	T2 value2;

	base(void) { value1 = 0; value2 = 0; };
	base(T1 pVal1, T2 pVal2) { value1 = pVal1; value2 = pVal2; };

	friend std::ostream& operator <<(std::ostream& out, const base& bs);

	virtual ~base() {}
};

template <class T1, class T2>
std::ostream& operator <<(std::ostream& out, const base<T1, T2>& bs) {
	out << "base " << '\n' << "value1 : " << bs.value1 << '\n' << "value2 : " << bs.value2 << '\n';

	return out;
};

