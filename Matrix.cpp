#include "Matrix.h"
#include <iostream>


template <class T>
int Matrix<T>::getSize() { return size; }

template <class T>
void newElement( int i, T element) {
	
		tip [i] = element;;
	
	
}

template <class T>
Matrix<T> Matrix<T>::operator + ( Matrix<T>& matrix) {
	Matrix newMatrix;
	int minSize = (size < matrix.size) ? size : matrix.size;
	newMatrix.size = (size > matrix.size) ? size : matrix.size;

	for (int i = 0; i < newMatrix.size; ++i) {
		if (i < minSize) {
			newMatrix[i] = tip[i] + matrix[i];
		} else {
			if (size > matrix.size) newMatrix[i] = tip[i];
			else newMatrix[i] = matrix[i];
		}
	}
	newMatrix.ID = (ID < matrix.ID) ? ID : matrix.ID;
	return newMatrix;
}

template <class T>
Matrix<T> Matrix<T>::operator += (Matrix<T>& matrix) {
	return (this + matrix);
}

template <class T>
Matrix<T> Matrix<T>::operator + (T element) {
	for (int i = 0; i < size; ++i) tip[i] += element;
	return this;
}

template <class T>
Matrix<T> Matrix<T>:: operator += (T element) {
	return (this + element);
}

template <class T>
Matrix<T> Matrix<T>::operator -(Matrix<T>& matrix){
	Matrix newMatrix;
	int minSize = (size < matrix.size) ? size : matrix.size;
	newMatrix.size = (size > matrix.size) ? size : matrix.size;

	for (int i = 0; i < newMatrix.size; ++i) {
		if (i < minSize) {
			newMatrix[i] = tip[i] - matrix[i];
		}
		else {
			if (size > matrix.size) newMatrix[i] = tip[i];
			else newMatrix[i] = matrix[i];
		}
	}
	newMatrix.ID = (ID < matrix.ID) ? ID : matrix.ID;
	return newMatrix;
}

template <class T>
Matrix<T> Matrix<T>:: operator - (T element) {
	for (int i = 0; i < size; ++i) tip[i] -= element;
	return this;
}

template <class T>
Matrix<T> Matrix<T>::operator -=(Matrix<T>& matrix) {
	return (this - matrix);
}

template <class T>
Matrix<T> Matrix<T>:: operator -= (T element) {
	return (this - element);
}

template <class T>
Matrix<T> Matrix<T>::operator *(Matrix<T>& matrix) {
	Matrix newMatrix;
	int minSize = (size < matrix.size) ? size : matrix.size;
	newMatrix.size = (size > matrix.size) ? size : matrix.size;

	for (int i = 0; i < newMatrix.size; ++i) {
		if (i < minSize) {
			newMatrix[i] = tip[i] * matrix[i];
		}
		else {
			if (size > matrix.size) newMatrix[i] = tip[i];
			else newMatrix[i] = matrix[i];
		}
	}
	newMatrix.ID = (ID < matrix.ID) ? ID : matrix.ID;
	return newMatrix;
}

template <class T>
Matrix<T> Matrix<T>:: operator * (T element) {
	for (int i = 0; i < size; ++i) tip[i] *= element;
	return this;
}

template <class T>
Matrix<T> Matrix<T>::operator *=(Matrix<T>& matrix) {
	return (this * matrix);
}

template <class T>
Matrix<T> Matrix<T>:: operator *= (T element) {
	return (this * element);
}

template <class T>
Matrix<T> Matrix<T>::operator /(Matrix<T>& matrix) {
	Matrix newMatrix;
	int minSize = (size < matrix.size) ? size : matrix.size;
	newMatrix.size = (size > matrix.size) ? size : matrix.size;

	for (int i = 0; i < newMatrix.size; ++i) {
		if (i < minSize) {
			newMatrix[i] = tip[i] / matrix[i];
		}
		else {
			if (size > matrix.size) newMatrix[i] = tip[i];
			else newMatrix[i] = matrix[i];
		}

	}
	newMatrix.ID = (ID < matrix.ID) ? ID : matrix.ID;
	return newMatrix;
}

template <class T>
Matrix<T> Matrix<T>:: operator / (T element) {
	for (int i = 0; i < size; ++i) tip[i] *= element;
	return this;
}

template <class T>
Matrix<T> Matrix<T>::operator /=(Matrix<T>& matrix) {
	return (this / matrix);
}

template <class T>
Matrix<T> Matrix<T>:: operator /= (T element) {
	return (this / element);
}

//(+, –, *, / )