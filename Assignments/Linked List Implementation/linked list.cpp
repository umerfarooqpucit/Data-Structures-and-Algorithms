#include<iostream>
using namespace std;
#include"linked list.h"

int main()
{
	LinkedList l1;
	l1.insertAtHead(6);
	l1.insertAtHead(6);
	l1.insertAtHead(7);
	l1.insertAtHead(5);
	l1.insertAtHead(7);
	l1.insertAtHead(7);
	l1.insertAtTail(15);
	l1.insertAtTail(19);
	l1.insertAtTail(16);
	l1.display();
	cout<<endl;
	l1.insert(8,5);
	l1.display();
	cout<<endl;
	l1.deleteFromTail(5);
	l1.display();
	cout<<endl;
	l1.deleteFromHead();
	l1.display();
	cout<<endl;
	l1.deleteFromTail();
	l1.display();
	cout<<endl;
	cout<<endl;
	
	/*l1.deleteFromHead();
	l1.display();*/
	return 0;

}

