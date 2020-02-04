#include "../include/linked_list.hpp"

template <class Type>
void ListNode<Type>::setData(Type data){

	this -> data = data;

}

template <class Type>
Type ListNode<Type>::getData(void){

	return data;

}


template <class Type>
LinkedList<Type>::LinkedList(void){

	head = nullptr;

}

template <class Type>
LinkedList<Type>::~LinkedList(void){

	clear();

}

template <class Type>
unsigned int LinkedList<Type>::size(void){

	unsigned int size = 0;

	for(ListNode<Type>* curr = head; curr != nullptr; curr = curr -> next, size++);

	return size;

}

template <class Type>
ListNode<Type>* LinkedList<Type>::getAt(unsigned int pos){

	ListNode<Type>* curr = head;

	for(int i = 0; curr != nullptr && i < pos; curr = curr -> next, i++);

	return curr;

}

template <class Type>
bool LinkedList<Type>::push_front(Type data){

	ListNode<Type>* new_node = new ListNode<Type>();

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	new_node -> data = data;

	new_node -> next = head;

	head = new_node;

	return true;

}

template <class Type>
bool LinkedList<Type>::push_back(Type data){

	if(head == nullptr)
		return push_front(data);

	ListNode<Type>* new_node = new ListNode<Type>();

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	new_node -> data = data;

	new_node -> next = nullptr;

	ListNode<Type>* tail = head;

	for(; tail -> next != nullptr; tail = tail -> next);

	tail -> next = new_node;

	return true;

}

template <class Type>
bool LinkedList<Type>::insert(Type data, unsigned int pos){

	ListNode<Type>* new_node = new ListNode<Type>();

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	new_node -> data = data;

	if(pos == 0)
		return push_front(data);

	ListNode<Type>* prev = getAt(pos - 1);

	// position was not found
	if(prev == nullptr)
		return false;

	new_node -> next = prev -> next;

	prev -> next = new_node;

	return true;

}

template <class Type>
bool LinkedList<Type>::remove(ListNode<Type>* node){

	if(node == nullptr)
		return false;

	if(node == head){

		head = node -> next;

		delete node;

		return true;

	}

	LinkedList<Type>* prev = head;

	for(; prev != nullptr && prev -> next != node; prev = prev -> next);

	// node was not found
	if(prev == nullptr)
		return false;

	prev -> next = node -> next;

	delete node;

	return true;

} 

template <class Type>
bool LinkedList<Type>::remove(unsigned int pos){

	return remove(getAt(pos));

}

template <class Type>
void LinkedList<Type>::clear(void){

	ListNode<Type>* prev = nullptr;

	ListNode<Type>* curr = head;

	while(curr != nullptr){

		prev = curr;

		curr = curr -> next;

		delete prev;

	}

	head = nullptr;

}

template <class Type>
void LinkedList<Type>::print(void){

	ListNode<Type>* curr = head;

	std::cout << '[';

	while(curr != nullptr){

		std::cout << curr -> data;

		if((curr = curr -> next) != nullptr)
			std::cout << ", ";

	}

	std::cout << "]" << std::endl;

}
