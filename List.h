#pragma once
#include <iostream>

using namespace std;

struct Node{
	char data;
	Node* Next;
};

class List{
	Node* Head;
	Node* Tail;
	int Count;

public:
	//Конструктор
	List();
	//Добавление элемента в список
	void Add(char data);
	//Удаление элемента списка
	void Del();
	//Удаление всего списка
	void DelAll();
	//Распечатка содержимого списка
	void Print();
	//Получение количества элементов,
	int GetCount();
	//проверка скобок
	bool brace();
	//Деструктор
	~List();
};

