#include "linkedlist.h"
#include "Node.h"
#include <iostream>
using namespace std;

// Default constructor to initialize an empty linked list.
template <class T>
LinkedList<T>::LinkedList() :head(NULL) {}

// Destructor to deallocate all nodes in the linked list.
template<class T>
LinkedList<T>::~LinkedList() {
	Node<T>* cursor, * next;
	cursor = head;
	while (cursor != NULL) {
		next = cursor->next;
		delete cursor;
		cursor = next;
	}
	head = NULL;
}

// Inserts a new node at the beginning of the list.
template<class T>
void LinkedList<T>::insertAtBeginning(const T& data) {
	Node<T>* newNode = new Node<T>();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

// Inserts a new node at the end of the list.
template<class T>
void LinkedList<T> ::insertAtEnd(const T& data) {
	if (isEmpty()) {
		insertAtBeginning(data);
		return;
	}

	Node<T>* newNode, * tail;

	newNode = new Node<T>();
	newNode->data = data;
	newNode->next = NULL;

	tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	tail->next = newNode;
}

// Deletes a node with the given data from the list.
template<class T>
void LinkedList<T> ::deleteNode(const T& data) {
	if (isEmpty()) {
		cout << "\nList is empty\n";
		return;
	}

	Node<T>* cursor = head;

	// Handle head node deletion
	if (cursor->data == data) {
		head = head->next;
		delete cursor;
		cout << "\nHead node with data " << data << " is deleted." << endl;
		return;
	}

	// Find the node to delete
	Node<T>* prev = NULL;
	while (cursor != NULL && cursor->data != data)
	{
		prev = cursor;
		cursor = cursor->next;
	}

	// If node not exist
	if (cursor == NULL) {
		cout << "\nNode with data " << data << " is not found." << endl;
		return;
	}

	// Node found
	prev->next = cursor->next;
	delete cursor;
	cout << "\nNode with data " << data << " is deleted." << endl;
}

// Prints the elements of the linked list.
template <class T>
void LinkedList<T>::printList() {
	if (isEmpty()) {
		cout << "\nList is empty\n";
		return;
	}

	Node<T>* cursor = head;
	cout << "\nList items are: \n";
	while (cursor != NULL) {
		cout << cursor->data << endl;
		cursor = cursor->next;
	}
}

// Checks if the list is empty.
template <class T>
bool LinkedList<T>::isEmpty() {
	return head == NULL;
}

// Returns the number of nodes in the list.
template <class T>
int LinkedList<T>::length() {
	int count = 0;
	Node<T>* cursor = head;
	while (cursor != NULL) {
		count++;
		cursor = cursor->next;
	}
	return count;
}