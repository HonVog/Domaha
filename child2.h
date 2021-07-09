#pragma once
#include "child.h"

template <class T1, class T2, class T3, class T4, class T5, class T6>
class child2 : virtual public child < T1, T2, T3, T4>
{
public:
    T5 value5;
    T6 value6;

	child2(void) :child < T1, T2, T3, T4>() {	value5 = 0;	value6 = 0;	}

	friend std::ostream& operator <<(std::ostream& os, const child2& bs);

    virtual ~child2() {}
};

template <class T1, class T2, class T3, class T4, class T5, class T6>
std::ostream& operator <<(std::ostream& os, const child2<T1, T2, T3, T4, T5, T6>& bs) {

	os << "class base " << '\n'
		<< "value1 : " << bs.value1 << '\n'
		<< "value2 : " << bs.value2 << '\n'
		<< "class child " << '\n'
		<< "value3 : " << bs.value3 << '\n'
		<< "value4 : " << bs.value4 << '\n'
		<< "class child2 " << '\n'
		<< "value5 : " << bs.value3 << '\n'
		<< "value6 : " << bs.value4 << '\n';

	return os;
}

