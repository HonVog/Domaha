#pragma once
#include "base.h"

template <class T1, class T2, class T3, class T4>
class child : virtual public base < T1, T2>
{
public:
	T3 value3;
	T4 value4;

	child() : base < T1, T2>() { value3 = 0; value4 = 0; };
	child(T3 pVal1, T4 pVal2):base < T1, T2>() { value3 = pVal1; value4 = pVal2; };
	child(T1 pVal1, T2 pVal2, T3 pVal3, T4 pVal4) :base < T1, T2> (pVal1, pVal2)
	{ value3 = pVal3; value4 = pVal4; };

		
	friend std::ostream& operator <<(std::ostream& os, const child& bs);

	virtual ~child()  {}
};

template <class T1, class T2, class T3, class T4>
std::ostream& operator <<(std::ostream& os, const child<T1, T2, T3, T4>& bs) {

	os << "class base " << '\n'
		<< "value1 : " << bs.value1 << '\n'
		<< "value2 : " << bs.value2 << '\n'
		<< "class child " << '\n'
		<< "value3 : " << bs.value3 << '\n'
		<< "value4 : " << bs.value4 << '\n';

	return os;
}

