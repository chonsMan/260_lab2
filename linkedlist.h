#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

struct node {
	char data;
	node* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);

private:
	node * head;
	node * curr;
	node * temp;
};
	
#endif // _LINKED_LIST_
