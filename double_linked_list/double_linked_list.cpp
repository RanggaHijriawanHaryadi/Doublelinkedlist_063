#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int noMhs;
	string nama;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START = NULL;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previeous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;

	Node* newNode = new Node(); //step1
	newNode->noMhs = nim; // step 2
	newNode->nama = nm; // step 2

	/*insert a node in the begining of a doubly - Linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = START; // step 3
			if (START !=NULL)
			START->prev = newNode; // step 4
			newNode->prev = NULL; // STEP 5
			START = newNode; // step 5
			return;
	}
	/*Instrting a Node Between tes Nodes in the list*/
	Node* current = START; // 1.a
	Node* privous = NULL; // 1.b
	while (current->next != NULL && current->next->noMhs < nim) // step 1.c
	{
		privous = current; // 1.d
		current = current->next; //1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll number not allowe" << endl;
		return;
	}

	newNode->next = current->next;// step 4
	newNode->prev = current; // step 5
	if (current->next != NULL)
		current->next->prev = newNode; //step 6
	current->next = newNode; //step 7
}

bool  DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START; // step 1.a
	*current = START;  // step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) { // step 1.c
		*previous = *current; // step 1.d
		*current = (*current)->next; //step 1.e
	}
	return (*current != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNo, &previous, &current) == false) 
		return false;
	if (current->next != NULL)
		current->next->prev = previous; //step 2
	if (previous != NULL)
		previous->next = current->next; //step 3
	else
		START = current->next;
	
	delete current; // step 4
	return true;
}

bool DoubleLinkedList::listEmpty() {
	return (START == NULL);
}