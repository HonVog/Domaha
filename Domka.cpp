/*
Курс
«Объектно-ориентированное
программирование на C++»
Встреча №18
Тема: Наследование
Задание 1.
Создать базовый класс «Домашнее животное» и производные классы «Собака», «Кошка», «Попугай». С помощью
конструктора установить имя каждого животного и его
характеристики.
*/

#include <iostream>
#include "Cat.h"
#include "Dog.h"
#include "Parrot.h"

int main()
{
    Cat cat{ "Snehok" };
    cat._Print();
    Dog dog{ "Tuzik" };
    dog._Print();
    Parrot parrot{ "Thihik" };
    parrot._Print();

    
}


