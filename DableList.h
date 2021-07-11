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
	List* prev, * next; // ������, �����

};

template<class T> class DableList: public List <T> , virtual public Abstrac
{
protected:
	List <T>* Prev;
	List <T>* Next; // ������, ����� 
public:
	// ����������� �����������
	DableList(const DableList& dableList); 
	//������� �����������
	DableList();
	// ���������� ������
	virtual ~DableList(); 
	// ���������� ������� ������
	void DellAll();
	//���������� � ����� ������
	void AddTail(T n);
	//�������� ����������
	int GetSize();
	//�������� ������� ������
	DableList* GetElem(T);
	//������� ���� ������
	void DellAll();                     
	//�������� ��������, ���� �������� �� �����������,�� ������� ��� �����������
	void Del(int pos = 0); 
	//������� ��������, ���� �������� �� �����������, �� ������� ��� �����������
	void Insert(int pos = 0);
	//���������� � ������ ������
	void AddHead(T n);
	//������ ������
	void Print() override;
	//������ ������������� ��������
	void Print(int pos) override;
    // =
	DableList& operator = (const DableList <T>&);
	//�������� ���� �������
	DableList operator + (const DableList <T>&);
	//��������� �� ���������
	bool operator == (const DableList <T>&);
	bool operator != (const DableList <T>&);
	bool operator <= (const DableList <T>&);
	bool operator >= (const DableList <T>&);
	bool operator < (const DableList <T>&);
	bool operator > (const DableList <T>&);

};

