#ifndef NODE_h
#define NODE_h
#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(){
	data=0;
	next=NULL;
	}
};
class LinkedList
{
	node* head;
	node* tail;
	int size;
public:
	LinkedList(){
	head=NULL;
	tail=NULL;
	size=0;}
	void insertAtHead(int value){
		node *n=new node();
		n->data=value;
		n->next=head;
		head=n;
		size++;
	}
	void insertAtTail(int value){
		node *n=new node();
		node * p=head;
		while(p->next!=NULL){
			p=p->next;
		}
		n->data=value;
		p->next=n;
		n->next=NULL;
		size++;
	}
	void insert(int value,int i){
		node *p=head;
		node *n=new node();

		for(int j=0;j<i-1;j++){
			p=p->next;
		}
		node* temp=p->next;
		p->next=n;
		n->data=value;
		n->next=temp;
		size++;
	}
	void deleteFromHead(){
		node* temp=head->next;
		head->next=NULL;
		head=temp;
		size--;
	}
	void deleteFromTail(){
		node *p=head;
		for(int i=0;i<size-1;i++){
			p=p->next;
		}
		tail=p;
		p->next=NULL;
		size--;
	}
	void deleteFromTail(int i){
		node *p=head;
		for(int j=0;j<i-1;j++){
			p=p->next;
		}
		node *temp=p->next;
		temp=temp->next;
		p->next=temp;
		size--;
	}
	void display(){
		node *p=head;
		for(int j=0;j<size;j++){
			cout<<p->data<<" ";
			p=p->next;
		}
	}
};
#endif