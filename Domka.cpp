/*
Тема: Шаблоны классов
Задание.
Создайте шаблонный класс матрица. Необходимо реализовать динамическое выделение памяти, очистку памяти,
заполнение матрицы с клавиатуры, заполнение случайными значениями, отображение матрицы, арифметические
операции с помощью перегруженных операторов (+, –,
*, /), поиск максимального и минимального элемента.
*/

#include <iostream>
#include "Matrix.h"
#include <ctime>

int main()
{
    Matrix<double> mat1(10);
    Matrix<double> mat2(10);

    for (int i = 0; i < 10; ++i) {
        
        mat1(i) = {rand() % 10 };
        mat2(i) = rand() % 10;

        std::cout << mat1.print(i) << '\n'
            << mat2.print(i) << std::endl;
    }

    mat1 += 1;
    mat2 = mat1 + mat2;

    for (int i = 0; i < 10; ++i) {

        std::cout << mat1.print(i) << '\n'
            << mat2.print(i) << std::endl;
    }

    return 0;
}


