#pragma once
// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iostream>


//struct Node {
//	int data;
//	Node* next;
//};

class Node {
	
public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;
	
public: 
	LinkedList() : head(nullptr), tail(nullptr), length(0) {}

	void addNodeToHead(int data);
	void addNodeToTail(int data);
	bool isValidIndex(int pos) const;
	void addNode(int data,int position);
	void printList();
	int removeHead();
	int removeTail();
	int removeAt(int pos);
	int getItem(int pos);
	int getHead();
	int getTail();
	void removeValue(int data);
	int getLength() {
		return length;
	};
};

#endif // LINKEDLIST_H

