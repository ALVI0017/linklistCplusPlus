
#pragma once
// LinkedList.h

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <iostream>


//struct Node {
//	int data;
//	Node* next;
//};

class NodeDD {

public:
	int data;
	NodeDD* next;
	NodeDD* prev;
	NodeDD(int data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};

class DoublyLinkedList
{
private:
	NodeDD* head;
	NodeDD* tail;
	int length;

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

	void addNodeToHead(int data);
	void addNodeToTail(int data);
	void addNode(int data, int position);
	void printList();

	/*bool isValidIndex(int pos) const;
	int removeHead();
	int removeTail();
	int removeAt(int pos);
	int getItem(int pos);
	int getHead();
	int getTail();
	void removeValue(int data);*/
	int getLength() {
		return length;
	};
};

#endif // LINKEDLIST_H

