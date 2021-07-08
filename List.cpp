#include "List.h"

List::List() {	Head = Tail = NULL;	Count = 0; }

List::~List() { DelAll(); }

int List::GetCount(){	return Count; }

void List::Add(char data) {
	Node* temp = new Node;
	temp->data = data;  temp->Next = NULL;

	if (Head) { Tail->Next = temp; Tail = temp; }
	else { Head = Tail = temp; }
}

void List::Del(){
	Node* temp = Head;
	Head = Head-> Next;
	delete temp;
}

void List::DelAll(){ while (Head != 0)  Del();  }

void List::Print(){
	Node* temp = Head;
	while (temp){
		cout << temp->data;
		temp = temp->Next;
	}
	cout << "\n";
    if (!brace()) {
        cout << "Строка заполнена неверно";
    }
    else {
        cout << "Строка заполнена верно";
    }
}

bool List::brace() {
    Node* temp = Head;
    char open ='{';
    char clous = ')';
    while (temp) {
        switch (temp->data) {
        case '(':
        case '{':
        case '[':
            open = temp->data;
            break;
        case ')':
        case '}':
        case ']':
            clous = temp->data;
            if (open != clous) {
                return false;
            }
            break;
        }
    }
    return true;
}
