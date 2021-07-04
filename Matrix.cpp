#include "Matrix.h"

template <class  T>
void Matrix<T>::Cliner() {
	delegate[] tip; size = 0; tip = nullptr; ID = 0;
};

template <class T>
T& Matrix<T>::operator[] (int index) {
	assert(index >= 0 && index < MAX)
		return tip[index];
}

template <class T>
int Matrix<T>::getSize() { return size; }

template <class T>
void Matrix<T>::operator ()(T element) {
	if (ID < MAX) { tip[ID] = element; ++ID; return; }

	std::cout << " the arrey is full";
}

template <class T>
Matrix<T> Matrix<T>::operator + ( Matrix& matrix) {
	Matrix newMatrix;


}
//(+, –, *, / )
