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
	//�����������
	List();
	//���������� �������� � ������
	void Add(char data);
	//�������� �������� ������
	void Del();
	//�������� ����� ������
	void DelAll();
	//���������� ����������� ������
	void Print();
	//��������� ���������� ���������,
	int GetCount();
	//�������� ������
	bool brace();
	//����������
	~List();
};

