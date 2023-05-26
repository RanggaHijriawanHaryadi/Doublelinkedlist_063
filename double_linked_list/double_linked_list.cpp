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
	void addNode();
	void search(int rollNo, Node** priveous, Node** current);
	bool delateNode(int rollNo);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

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
			START->prev = newNode;
			newNode->prev = NULL; // STEP 5
			START = newNode; // step 6
			return;
	}

}

