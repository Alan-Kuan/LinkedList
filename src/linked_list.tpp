#include "../include/linked_list.hpp"

//----------- ListNode -----------//
template <class Type>
void ll::ListNode<Type>::setData(Type data){

	this -> data = data;

}

template <class Type>
Type ll::ListNode<Type>::getData(void) const{

	return data;

}


//----------- LinkedList -----------//
template <class Type>
ll::LinkedList<Type>::LinkedList(std::initializer_list<Type> init): head(nullptr), _size(0){

	for(const Type& item : init)
		push_back(item);

}

template <class Type>
ll::LinkedList<Type>::~LinkedList(void){

	clear();

}

template <class Type>
size_t ll::LinkedList<Type>::size(void) const{

	return _size;

}

template <class Type>
ll::ListNode<Type>* ll::LinkedList<Type>::at(int pos) const{

	if(pos < 0 || pos >= _size)
		return nullptr;

	ll::ListNode<Type>* curr = head;

	for(int i = 0; i < pos; curr = curr -> next, i++);

	return curr;

}

template <class Type>
ll::ListNode<Type>* ll::LinkedList<Type>::find(Type data) const{

	ll::ListNode<Type>* curr = head;

	for(; curr != nullptr && curr -> data != data; curr = curr -> next);

	return curr; // returns nullptr if the required node was not found

}

template <class Type>
bool ll::LinkedList<Type>::push_front(Type data){

	ll::ListNode<Type>* new_node = new ll::ListNode<Type>(data, head);

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	head = new_node;

	_size++;

	return true;

}

template <class Type>
bool ll::LinkedList<Type>::push_back(Type data){

	if(head == nullptr)
		return push_front(data);

	ll::ListNode<Type>* new_node = new ll::ListNode<Type>(data);

	// memory allocation failed
	if(new_node == nullptr)
		return false;
	
	ll::ListNode<Type>* tail = head;

	for(; tail -> next != nullptr; tail = tail -> next);

	tail -> next = new_node;

	_size++;

	return true;

}

template <class Type>
bool ll::LinkedList<Type>::insert(Type data, int pos){

	if(pos == 0)
		return push_front(data);

	ll::ListNode<Type>* prev = at(pos - 1);

	// position was not found
	if(prev == nullptr)
		return false;

	ll::ListNode<Type>* new_node = new ll::ListNode<Type>(data, prev -> next);

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	prev -> next = new_node;

	_size++;

	return true;

}

template <class Type>
bool ll::LinkedList<Type>::remove(ListNode<Type>* node){

	if(node == nullptr)
		return false;
	
	ll::ListNode<Type>** indirect = &head;

	for(; *indirect != nullptr && *indirect != node; indirect = &((*indirect) -> next));

	// the node is not in the list
	if(*indirect == nullptr)
		return false;

	*indirect = (*indirect) -> next;

	delete node;

	_size--;

	return true;

} 

template <class Type>
bool ll::LinkedList<Type>::remove(int pos){

	return remove(at(pos));

}

template <class Type>
void ll::LinkedList<Type>::clear(void){

	ll::ListNode<Type>* prev = nullptr;

	ll::ListNode<Type>* curr = head;

	while(curr != nullptr){

		prev = curr;

		curr = curr -> next;

		delete prev;

	}

	head = nullptr;

	_size = 0;

}

template <class Type>
void ll::LinkedList<Type>::print(void) const{

	ll::ListNode<Type>* curr = head;

	std::cout << '[';

	while(curr != nullptr){

		std::cout << curr -> data;

		if((curr = curr -> next) != nullptr)
			std::cout << ", ";

	}

	std::cout << "]" << std::endl;

}

template <class Type>
Type& ll::LinkedList<Type>::operator[](int idx){

	ListNode<Type>* node = at(idx);

	if(node == nullptr)
		throw std::out_of_range("The given index was out of range of the linked list!");

	return node -> data;

}

template <class Type>
Type ll::LinkedList<Type>::operator[](int idx) const{

	ListNode<Type>* node = at(idx);

	if(node == nullptr)
		throw std::out_of_range("The given index was out of range of the linked list!");

	return node -> data;

}
