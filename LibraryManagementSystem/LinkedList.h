#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList
{
private:
	Node<T>* head;

public:
	LinkedList();
	~LinkedList();
	void insertAtBeginning(const T& data);
	void insertAtEnd(const T& data);
	void deleteNode(const T& data);
	void printList();
	bool isEmpty();
	int length();
};

#endif
        