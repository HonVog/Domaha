#include "DableList.h"

using namespace std;

template<class T> DableList<T>::DableList()
{
	//���������� ������ ����
	Prev = Next = NULL;
	size = ZIRO;
}

template<class T> DableList<T>::DableList (const DableList & L)
{
	Prev = Next = NULL;
	size = ZIRO;

	//������ ������, �� �������� ��������
	DableList <T>* temp = L.Prev;

	//���� �� ����� ������
	while (temp)
	{
		//���������� ������
		AddTail(temp-> data);
		temp = temp-> next;
	}
}

template<class T> DableList<T>::~DableList() { DelAll(); }//������� ��� ��������

template<class T> void DableList<T>::AddHead(T n)
{
	DableList<T>* temp = new DableList;//����� �������
	temp-> prev = 0; //����������� ���
	temp->data = n;//��������� ������
	temp->next = Prev;//��������� - ������ ������

	//���� �������� ����?
	if (Prev != ZIRO)  Prev->prev = temp;

	//���� ������� ������, �� �� ������������ � ������ � �����, ����� ����� ������� - ��������
	(size == ZIRO)? Prev = Next = temp : Prev = temp;
	
	++ size;
}

template<class T> void DableList <T>:: AddTail(T n)
{
	//������� ����� �������
	DableList <T>* temp = new DableList;

	//���������� ���
	temp->next = 0;

	//��������� ������
	temp->data = n;

	//���������� - ������ �����
	temp->prev = Tail;

	//���� �������� ����?
	if (Next != 0)
		Next->next = temp;

	//���� ������� ������, �� �� ������������ ������ � �����
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
	//���� �������� ����������� ��� ����� 0, �� ����������� ���
	if (pos == ZIRO) { cout << "Input position: "; cin >> pos; }

	//������� �� 1 �� size?
	if (pos < MIN || pos > size + 1) { cout << "Incorrect position !!!\n"; return; }

	//���� ������� � ����� ������, ����������� ������
	if (pos == size + 1) { 
		T dataNew;
		cout << "Input new data: ";
		cin >> data;

		AddTail(dataNew);//���������� � ����� ������
		return;
	} else if (pos == MIN) { //����������� ������
		T dataNew;
		cout << "Input new data: ";
		cin >> data;

		//���������� � ������ ������
		AddHead(data);
		return;
	}

	int i = 1;//�������
	DableList* Ins = Prev;//����������� �� ������ n - 1 ���������

	while (i < pos) { //������� �� ��������, ����� ������� �����������	
		Ins = Ins-> next;
		++i;
	}
	
	DableList <T>* PrevIns = Ins->prev;//������� �� ��������, ������� ������������
	DableList <T> * temp = new DableList; //������� ����� �������

	cout << "Input new data: "; //������ ������
	cin >> temp->data;

	if (PrevIns != ZIRO && size != MIN) PrevIns->next = temp;  //��������� ������
		
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;

	++size;
}

template<class T> void DableList<T>::Del(int pos) {
	
	if (pos == ZIRO) { //���� �������� ����������� ��� ����� 0, �� ����������� ���
		cout << "Input position: ";
		cin >> pos;
	}
	if (pos < MIN || pos > size) {	//������� �� 1 �� size?
		cout << "Incorrect position !!!\n";//�������� �������
		return;
	}
	int i = MIN;//�������
	DableList* Del = Prev;
	while (i < pos) {	Del = Del->next;	++i; }
	
	DableList* PrevDel = Del->prev;//������� �� ��������, ������� ������������ ����������

	DableList* AfterDel = Del->next;//������� �� ��������, ������� ������� �� ��������� 

	if (PrevDel != ZIRO && size != MIN) { PrevDel->next = AfterDel; }//���� ������� �� ������

	if (AfterDel != ZIRO && size != MIN) { AfterDel->prev = PrevDel; }//���� ������� �� �����

	//��������� �������?
	if (pos == 1) { Prev = AfterDel; }
	if (pos == size) { Next = PrevDel; }
	
	delete Del; //�������� ��������
	--size ;
}

template<class T> void DableList<T>::Print(int pos) {
	if (pos < MIN || pos > size) {//������� �� 1 �� size?	
		cout << "Incorrect position !!!\n"; //�������� �������
		return;
	}

	DableList* temp;	
	if (pos <= size / 2) { //������ � ������		
		temp = Prev;
		int i = 1;
		while (i < pos) { //��������� �� ������� ��������
			temp = temp->next;
			++i;
		}
	} else { //������ � ������		
		temp = Next;
		int i = 1;
		while (i <= size - pos) { //��������� �� ������� ��������	
			temp = temp->prev;
			++i;
		}
	}
	
	cout << pos << " element: "; //����� ��������
	cout << temp->data << endl;
}

template<class T> void DableList<T>::Print()
{
	//���� � ������ ������������ ��������, �� ��������� �� ���� � �������� ��������, ������� � ��������� 
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
	//���� �������� ��������, ������� �� ������ � ������
	while (size != 0)
		Del(1);
}

template<class T> int DableList<T>::GetSize() { return size; }

template<class T> DableList <T>* DableList<T> :: GetElem( T pos) {
	DableList* temp = Prev;
	if (pos < 1 || pos > size) {//������� �� 1 �� size?	
		cout << "Incorrect position !!!\n"; //�������� �������
		return 0;
	}

	int i = 1;
	while (i < pos && temp != ZIRO) { temp = temp->next; ++i; } //���� ������ ��� �������

	return (temp == 0) ? 0 : temp;
}	 

template<class T> DableList <T>& DableList<T> ::operator = (const DableList& L){ 
	if (this == &L) return *this; //�������� ������������ �������� "������ ����"
	
	this-> ~DableList(); // DelAll();//�������� ������� ������

	DableList* temp = L.Prev;//�������� ��������
	
	while (temp != ZIRO) { AddTail(temp->data);	temp = temp->next; }

	return *this;
}

template<class T> DableList <T> DableList<T>:: operator + (const DableList& L){
	//������� �� ��������� ������ �������� ������� ������
	DableList<T> Result (*this);
	DableList <T>* temp = L.Prev;
	//��������� �� ��������� ������ �������� ������� ������
	while (temp != 0)
	{
		Result.AddTail(temp->data);
		temp = temp->next;
	}
	return Result;
}

template<class T> bool DableList<T>::operator == (const DableList& L){
	//��������� �� ����������
	if (size != L.size)
		return false;
	DableList* t1, * t2;
	t1 = Prev;
	t2 = L.Prev;
	while (t1 != ZIRO) { //��������� �� ����������	
		if (t1->data != t2->data) { return false; }//������� ������, ������� ��������� �� ���������� ��������
		t1 = t1->next;
		t2 = t2->next;
	}
	return true;
}

template<class T> bool DableList<T>::operator != (const DableList& L) { return !(*this == L); }

template<class T> bool DableList<T>::operator >= (const DableList& L) {	
	if (size > L.size) return true; //��������� �� ����������
	if (*this == L) return true; //��������� �� ����������
	return false;
}

template<class T> bool DableList<T>::operator <= (const DableList& L){
	if (size < L.size) return true;//��������� �� ����������
	if (*this == L) return true;//��������� �� ����������
	return false;
}

template<class T> bool DableList<T>::operator > (const DableList& L) { return (size > L.size); }

template<class T> bool DableList<T>::operator < (const DableList& L) { return (size < L.size); }
