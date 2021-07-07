#pragma once
#include <iostream>
#include <cassert>

using namespace std;

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <class  T>
class Matrix
{
	const int MAX = 100; // максимальный размер
	const int MIN = 0; // минимальный размер 
	int ID; // последняя заполненая позиция
	int size; // размер
	T *tip; // сам массив

public:

	Matrix () {
		size = 0; tip = nullptr; ID = 0;
	};

	Matrix (int size) {
		if (size > MIN) { Cliner(); return; }

		if (size < MAX) { this->size = MAX; tip = new T[MAX]; return;  }

		this->size = size; tip = new T[size]; ID = 0;
	};

	Matrix (Matrix& matrix) {
		Cliner();
		size = matrix.size;
		ID = matrix.ID;
		tip = new T[size];
		for (int i = 0; i < size; ++i) { tip[i] = matrix[i]; }
	}



	void newElement( int i, T element);

	Matrix& operator = (Matrix& matrix) { return (*this(matrix)); }

	Matrix operator + (Matrix& matrix);  // +
	Matrix operator += (Matrix& matrix);

	Matrix operator + (T element);
	Matrix operator += (T element);

	Matrix operator - (Matrix& matrix); // -
	Matrix operator -= (Matrix& matrix);

	Matrix operator - (T element);
	Matrix operator -= (T element);

	Matrix operator * (Matrix& matrix); // *
	Matrix operator *= (Matrix& matrix);

	Matrix operator * (T element);     
	Matrix operator *= (T element);

	Matrix operator / (Matrix& matrix); // '/'
	Matrix operator /= (Matrix& matrix);

	Matrix operator / (T element);     
	Matrix operator /= (T element);
	
	int getSize();

	T print(int i) {
		return tip[i];
	}

	~Matrix() { delete [] tip; };

	void Cliner() {
		delete[] tip;
		size = 0; tip = nullptr; ID = 0;
	};

};

