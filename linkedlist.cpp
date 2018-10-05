#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}


LinkedList::~LinkedList()
{
	node * curr = head;
	while(head){
		curr = head->next;
		delete head;
		head = curr;
	}
}

void LinkedList::add (char ch)
{
	node * newNode = new node; //node * points to new node
	newNode->next = NULL; //find node newNode points to. Access its next element. Set it equal to NULL
	newNode->data = ch; //Node holds data passed in
	
	if(head != NULL) { //if list exists
		curr = head;
		while(curr->next != NULL && curr->data < ch) { //while not at last node in list
			curr = curr->next;
		}//while
		newNode->next = curr->next;
		curr->next = newNode;
	}//if

	else head = newNode;
}//add

bool LinkedList::find(char ch){
	while(curr != NULL){
		if (curr->data == ch)
			return true;
		curr = curr->next;
	}
	return false;
}

bool LinkedList::del (char ch) {
	node * del_ptr = NULL;
	curr = head;

	while(curr != NULL && curr->data != ch) {
		curr = curr->next;
	}//while

	if(curr != NULL) {
		del_ptr = curr;
		curr = curr->next; //get curr pointer out of here

		//Need to connect temp and curr 
		if (del_ptr == head) {
			head = curr;
		}
		delete del_ptr;
		return true;
	}//if
	else {
		delete del_ptr;
		del_ptr = NULL;
		return false;
	}//else
}//del


ostream& operator << (ostream& out, LinkedList& list) {
	node * p;
	for(p = list.head; p!=0; p = p->next)
		out << p->data;
	out<<endl;
	return out;
} 




















