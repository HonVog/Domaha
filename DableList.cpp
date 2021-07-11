#include "DableList.h"

using namespace std;

template<class T> DableList<T>::DableList()
{
	//Изначально список пуст
	Prev = Next = NULL;
	size = ZIRO;
}

template<class T> DableList<T>::DableList (const DableList & L)
{
	Prev = Next = NULL;
	size = ZIRO;

	//Голова списка, из которого копируем
	DableList <T>* temp = L.Prev;

	//Пока не конец списка
	while (temp)
	{
		//Передираем данные
		AddTail(temp-> data);
		temp = temp-> next;
	}
}

template<class T> DableList<T>::~DableList() { DelAll(); }//Удаляем все элементы

template<class T> void DableList<T>::AddHead(T n)
{
	DableList<T>* temp = new DableList;//новый элемент
	temp-> prev = 0; //Предыдущего нет
	temp->data = n;//Заполняем данные
	temp->next = Prev;//Следующий - бывшая голова

	//Если элементы есть?
	if (Prev != ZIRO)  Prev->prev = temp;

	//Если элемент первый, то он одновременно и голова и хвост, иначе новый элемент - головной
	(size == ZIRO)? Prev = Next = temp : Prev = temp;
	
	++ size;
}

template<class T> void DableList <T>:: AddTail(T n)
{
	//Создаем новый элемент
	DableList <T>* temp = new DableList;

	//Следующего нет
	temp->next = 0;

	//Заполняем данные
	temp->data = n;

	//Предыдущий - бывший хвост
	temp->prev = Tail;

	//Если элементы есть?
	if (Next != 0)
		Next->next = temp;

	//Если элемент первый, то он одновременно голова и хвост
	try {
		if (size != 0) { throw 0; }
		Prev = Next = temp;
	}
	catch (...) {
		Tail = temp;
	}

	++ size;
}

template<class T> void DableList<T>::Insert(int pos)
{
	//если параметр отсутствует или равен 0, то запрашиваем его
	if (pos == ZIRO) { cout << "Input position: "; cin >> pos; }

	//Позиция от 1 до size?
	if (pos < MIN || pos > size + 1) { cout << "Incorrect position !!!\n"; return; }

	//Если вставка в конец списка, Вставляемые данные
	if (pos == size + 1) { 
		T dataNew;
		cout << "Input new data: ";
		cin >> data;

		AddTail(dataNew);//Добавление в конец списка
		return;
	} else if (pos == MIN) { //Вставляемые данные
		T dataNew;
		cout << "Input new data: ";
		cin >> data;

		//Добавление в начало списка
		AddHead(data);
		return;
	}

	int i = 1;//Счетчик
	DableList* Ins = Prev;//Отсчитываем от головы n - 1 элементов

	while (i < pos) { //Доходим до элемента, перед которым вставляемся	
		Ins = Ins-> next;
		++i;
	}
	
	DableList <T>* PrevIns = Ins->prev;//Доходим до элемента, который предшествует
	DableList <T> * temp = new DableList; //Создаем новый элемент

	cout << "Input new data: "; //Вводим данные
	cin >> temp->data;

	if (PrevIns != ZIRO && size != MIN) PrevIns->next = temp;  //настройка связей
		
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	++size;
}

template<class T> void DableList<T>::Del(int pos) {
	
	if (pos == ZIRO) { //если параметр отсутствует или равен 0, то запрашиваем его
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < MIN || pos > size) {	//Позиция от 1 до size?
		cout << "Incorrect position !!!\n";//Неверная позиция
		return;
	}
	int i = MIN;//Счетчик
	DableList* Del = Prev;
	while (i < pos) {	Del = Del->next;	++i; }
	
	DableList* PrevDel = Del->prev;//Доходим до элемента, который предшествует удаляемому

	DableList* AfterDel = Del->next;//Доходим до элемента, который следует за удаляемым 

	if (PrevDel != ZIRO && size != MIN) { PrevDel->next = AfterDel; }//Если удаляем не голову

	if (AfterDel != ZIRO && size != MIN) { AfterDel->prev = PrevDel; }//Если удаляем не хвост

	//Удаляются крайние?
	if (pos == 1) { Prev = AfterDel; }
	if (pos == size) { Next = PrevDel; }
	
	delete Del; //Удаление элемента
	--size ;
}

template<class T> void DableList<T>::Print(int pos) {
	if (pos < MIN || pos > size) {//Позиция от 1 до size?	
		cout << "Incorrect position !!!\n"; //Неверная позиция
		return;
	}

	DableList* temp;	
	if (pos <= size / 2) { //Отсчет с головы		
		temp = Prev;
		int i = 1;
		while (i < pos) { //Двигаемся до нужного элемента
			temp = temp->next;
			++i;
		}
	} else { //Отсчет с хвоста		
		temp = Next;
		int i = 1;
		while (i <= size - pos) { //Двигаемся до нужного элемента	
			temp = temp->prev;
			++i;
		}
	}
	
	cout << pos << " element: "; //Вывод элемента
	cout << temp->data << endl;
}

template<class T> void DableList<T>::Print()
{
	//Если в списке присутствуют элементы, то пробегаем по нему и печатаем элементы, начиная с головного 
	if (size != ZIRO)
	{
		DableList* temp = Prev;
		cout << "( ";
		while (temp->next) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}

template<class T> void DableList<T>::DellAll() {
	//Пока остаются элементы, удаляем по одному с головы
	while (size != 0)
		Del(1);
}

template<class T> int DableList<T>::GetSize() { return size; }

template<class T> DableList <T>* DableList<T> :: GetElem( T pos) {
	DableList* temp = Prev;
	if (pos < 1 || pos > size) {//Позиция от 1 до size?	
		cout << "Incorrect position !!!\n"; //Неверная позиция
		return 0;
	}

	int i = 1;
	while (i < pos && temp != ZIRO) { temp = temp->next; ++i; } //Ищем нужный нам элемент

	return (temp == 0) ? 0 : temp;
}	 

template<class T> DableList <T>& DableList<T> ::operator = (const DableList& L){ 
	if (this == &L) return *this; //Проверка присваивания элемента "самому себе"
	
	this-> ~DableList(); // DelAll();//удаление старого списка

	DableList* temp = L.Prev;//Копируем элементы
	
	while (temp != ZIRO) { AddTail(temp->data);	temp = temp->next; }

	return *this;
}

template<class T> DableList <T> DableList<T>:: operator + (const DableList& L){
	//Заносим во временный список элементы первого списка
	DableList<T> Result (*this);
	DableList <T>* temp = L.Prev;
	//Добавляем во временный список элементы второго списка
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}
	return Result;
}

template<class T> bool DableList<T>::operator == (const DableList& L){
	//Сравнение по количеству
	if (size != L.size)
		return false;
	DableList* t1, * t2;
	t1 = Prev;
	t2 = L.Prev;
	while (t1 != ZIRO) { //Сравнение по содержанию	
		if (t1->data != t2->data) { return false; }//Сверяем данные, которые находятся на одинаковых позициях
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}

template<class T> bool DableList<T>::operator != (const DableList& L) { return !(*this == L); }

template<class T> bool DableList<T>::operator >= (const DableList& L) {	
	if (size > L.size) return true; //Сравнение по количеству
	if (*this == L) return true; //Сравнение по содержанию
	return false;
}

template<class T> bool DableList<T>::operator <= (const DableList& L){
	if (size < L.size) return true;//Сравнение по количеству
	if (*this == L) return true;//Сравнение по содержанию
	return false;
}

template<class T> bool DableList<T>::operator > (const DableList& L) { return (size > L.size); }

template<class T> bool DableList<T>::operator < (const DableList& L) { return (size < L.size); }
