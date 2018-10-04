#include "linkedlist.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

list::list() : head(NULL)
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}


list::~list()
{

}


void list::add (char ch)
{
	node_ptr newNode = new node; //node_ptr points to new node
	newNode->next = NULL; //find node newNode points to. Access its next element. Set it equal to NULL
	newNode->data = ch; //Node holds data passed in
	
	if(head != NULL) { //if list exists
		curr = head;
		while(curr->next != NULL && curr->data < ch) { //while not at last node in list
			curr = curr->next;
		}//while
		curr->next - newNode;
	}//if

	else head = newNode;
}//add

bool list::del (char ch) {
	node_ptr del_ptr = NULL;
	temp = head;
	curr = head;

	while(curr != NULL && curr->data != ch) {
		temp = curr; //keep temp one step behind (prev)
		curr = curr->next;
	}//while

	if(curr != NULL) {
		del_ptr = curr;
		curr = curr->next; //get curr pointer out of here

		//Need to connect temp and curr 
		temp->next = curr; //list is patched
		delete del_ptr;
		return true;
	}//if
	else {
		delete del_ptr;
		return false;
	}//else
}//del


ostream& operator << (ostream& out, LinkedLisk list) {
	alpha_numeric *p;
	for(p = list.front; p!=0; p->next)
		out << p->symbol;
	out<<endl;
	return out;
} 




















