#include "DoublyLinkList.h"
using namespace std;

void DoublyLinkedList::addNodeToHead(int data) {
	NodeDD* newNode = new NodeDD(data);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	length++;
}
void DoublyLinkedList::addNodeToTail(int data) {
	NodeDD* newNode = new NodeDD(data);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
	length++;

}
void DoublyLinkedList::addNode(int data, int pos) {

	/*if (pos == 0) {
		addNodeToHead(data);
		return;
	}
	if (pos > length - 1) {
		addNodeToTail(data);
		return;
	}

	if (pos < 0 || pos >= length) {
		cout << "Invalid position" << endl;
		return;
	}

	Node* newNode = new Node(data);
	newNode->data = data;
	newNode->next = nullptr;

	Node* cur = head;
	for (int i = 0; i < pos - 1; i++) {
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
	length++;*/
}

void DoublyLinkedList::printList() {
	NodeDD* cur = head;
	int counter = 0;
	while (cur != nullptr) {
		cout << counter << "--->{" << cur->data << "}";
		cout << endl;
		cur = cur->next;
		counter++;
	}
	cout << "Length ---> " << length;
	cout << endl;
}