#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList<int> l;

	l.printList();

	l.insertAtBeginning(10);
	l.insertAtBeginning(15);
	l.insertAtEnd(30);

	l.printList();

	cout << "\nNumber of nodes in the list is " << l.length() << endl;

	l.deleteNode(12);
	l.deleteNode(10);

	l.printList();

	cout << "\nNumber of nodes in the list is " << l.length() << endl;

	return 0;
}
