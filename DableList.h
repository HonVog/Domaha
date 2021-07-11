#pragma once
#include <iostream>
#include "Abstrac.h"

using namespace std;

enum {
	ZIRO = 0,
	MIN =1,
};

template<class T> struct List {
	T data;
	List* prev, * next; // голова, хвост

};

template<class T> class DableList: public List <T> , virtual public Abstrac
{
protected:
	List <T>* Prev;
	List <T>* Next; // голова, хвост 
public:
	// конструктор копирования
	DableList(const DableList& dableList); 
	//базовый конструктор
	DableList();
	// деструктор класса
	virtual ~DableList(); 
	// деструктор объекта класса
	void DellAll();
	//Добавление в конец списка
	void AddTail(T n);
	//Получить количество
	int GetSize();
	//Получить элемент списка
	DableList* GetElem(T);
	//Удалить весь список
	void DellAll();                     
	//Удаление элемента, если параметр не указывается,то функция его запрашивает
	void Del(int pos = 0); 
	//Вставка элемента, если параметр не указывается, то функция его запрашивает
	void Insert(int pos = 0);
	//Добавление в начало списка
	void AddHead(T n);
	//Печать списка
	void Print() override;
	//Печать определенного элемента
	void Print(int pos) override;
    // =
	DableList& operator = (const DableList <T>&);
	//сложение двух списков
	DableList operator + (const DableList <T>&);
	//сравнение по элементам
	bool operator == (const DableList <T>&);
	bool operator != (const DableList <T>&);
	bool operator <= (const DableList <T>&);
	bool operator >= (const DableList <T>&);
	bool operator < (const DableList <T>&);
	bool operator > (const DableList <T>&);

};

