#pragma once

using namespace std;

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <class  T>
class Matrix
{
	const int MAX = 100;
	const int MIN = 1;
	int ID;
	int size;
	T *tip;

public:

	Matrix() {
		size = 0; tip = nullptr; ID = 0;
	};

	Matrix(int size) {
		if (size > MIN) { Cliner(); return; }

		if (size < MAX) { this->size = MAX; tip = new T[MAX]; return;  }

		this->size = size; tip = new T[size];
	};

	void Cliner();

	T& operator[] (int index);

	void operator ()(T element);

	Matrix Matrix<T>::operator +(Matrix& matrix);
	
	int getSize();

	~Matrix() { delegate[] tip; };
};

