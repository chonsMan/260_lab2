#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

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
	typedef struct node
	{
		char data;
		node* next;
	}* node_ptr;

	node_ptr head;
	node_ptr curr;
	node_ptr temp;
};
	
#endif // _LINKED_LIST_
