#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <class Type>
class ListNode{

	Type data;

	ListNode* next;

};

template <class Type>
class LinkedList{

	LinkedList(void);

	~LinkedList(void);

private:
	ListNode<Type>* head;

public:
	unsigned int size(void);

	ListNode<Type>* getAt(unsigned int pos);

	bool push_front(Type data);

	bool push_back(Type data);

	bool insert(Type data, unsigned int pos);

	bool remove(ListNode<Type>* node);

	bool remove(unsigned int pos);

	bool clear(void);

};

#endif
