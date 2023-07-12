#include "Linklist.h"
using namespace std;
// Private function for index validation
bool LinkedList::isValidIndex(int pos) const {
	return pos >= 0 && pos < length;
}
//add
void LinkedList::addNodeToHead(int data) {
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;
	if (tail == nullptr) {
		tail = newNode;
	}
	length++;
}
void LinkedList::addNodeToTail(int data) {
	Node* newNode = new Node(data);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
	length = length + 1;

}
void LinkedList::addNode(int data, int pos) {
	if (pos == 0) {
		addNodeToHead(data);
		return;
	}
	if (pos > length - 1) {
		addNodeToTail(data);
		return;
	}
	if (pos < 0||pos>=length) {
		cout << "Invalid position" << endl;
		return;
	}
	Node* newNode = new Node(data);
	newNode->data = data;
	newNode->next = nullptr;
	
	Node* cur = head;
	for (int i = 0; i < pos-1; i++) {
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
	length++;
}

void LinkedList::printList() {
	Node* cur = head;
	int counter = 0;
	while (cur != nullptr) {
		cout << counter << "--->{" << cur->next << "--->" << cur->data << "}";
		cout << endl;
		cur = cur->next;
		counter++;
	}
	cout << "Length ---> " << length;
	cout << endl;
}
// Remove
int LinkedList::removeHead() {
	
	if (head == nullptr) {
		cout << "Error: List is empty" << endl;
		return -1; // Return an error value or throw an exception
	}
	int tempData = head->data;
	Node* removeHead = head;

	if (head->next == nullptr) {
		// Only one node in the list
		head = nullptr;
		tail = nullptr;
	}
	else {
		head = head->next;
	}
	delete removeHead;
	cout << "==================Removed Head===================" << endl;

	return tempData;
}
int LinkedList::removeTail() {
	if (head == nullptr) {
		cout << "List is empty. Cannot remove tail." << endl;
		return -1;
	}
	if (head->next == nullptr) {
		return removeHead();
	}

	Node* cur = head;
	Node* temp = cur->next;
	while (temp->next != nullptr) {
		cur = cur->next;
	}
	Node* removeNode = cur->next->next;
	int tempData = cur->next->data;
	cur->next = nullptr;
	tail = cur;
	length--;
	delete removeNode;
	cout << "==================Removed Tail===================" << endl;
	return tempData;
}
int LinkedList::removeAt(int pos) {
	if (!isValidIndex(pos)) {
		cout << "Error: Invalid position" << endl;
		return -1;
	}
	
	if (pos == 1) {
		return removeHead();
	}
	
	if (pos == length) {
		return removeTail();
	}

	Node* cur = head;
	for (int i = 1; i < pos - 1; i++) {
		cur = cur->next;
	}
	Node* removeNode = cur->next;
	int tempdata = cur->next->data;
	cur->next = cur->next->next;
	delete removeNode; // garbage collection
	length--;
	cout << "==================Removed At===================" << endl;
	return tempdata;
}

void LinkedList::removeValue(int data) {
	Node* cur = head;
	Node* prev = nullptr;
	bool dataFound = false;
	while (cur != nullptr) {
		if (cur->data == data) {
			if (prev == nullptr) {
				removeHead();
				cur = head;
			}
			else if (cur->next == nullptr) {
				removeTail();
				cur = nullptr;
			}
			else {
				Node* removeNode = cur;
				prev->next = cur->next;
				cur = cur->next;
				delete removeNode;
				length--;
			}
			dataFound = true;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}

	if (dataFound) {
		cout << "Data deleted." << endl;
	}
	else {
		cout << "No such data available." << endl;
	}
}
// getItem
int LinkedList::getItem(int pos) {
	if (!isValidIndex(pos)) {
		cout << "Error: Invalid positisasdson" << endl;
		return -1;
	}
	if (head == nullptr) {
		cout << "List is empty. Cannot remove tail." << endl;
		return -1;
	}
	
	Node* cur = head;
	for (int i = 0; i < pos-1; i++) {
		cur = cur->next;
	}
	int tempData = cur->data;
	cout << "==================Get data===================" << endl;
	return tempData;
}

int LinkedList::getHead() {
	if (head == nullptr) {
		cout << "Error: List is empty" << endl;
		return -1;
	}
	return head->data;
}
int LinkedList::getTail() {
	if (tail == nullptr) {
		cout << "Error: List is empty" << endl;
		return -1;
	}
	return tail->data;
}


//
//void LinkedList::removeValue(int data) {
//	// tracker cur prev
//
//	// while loop 
//	//	if data found
//	//		if head
//	//			removeHead()
//	//			cur = head;
//	//		else if tail
//	//			removetail
//	//			cur = nullptr
//	//		else
//	//			removeNode = cur;
//	//			prev->next = cur->next;
//	//			cur = cur->next
//	//			delete removeNode	
//	//			legnth--
//	//	else
//	//		prev = cur;
//	//		cur = cur->next
//}