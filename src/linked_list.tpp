#include "linked_list.hpp"

//----------- ListNode -----------//
template <class Type>
void Nlib::ListNode<Type>::setData(Type data){

	this -> data = data;

}

template <class Type>
Type Nlib::ListNode<Type>::getData(void) const{

	return data;

}


//----------- LinkedList -----------//
template <class Type>
Nlib::LinkedList<Type>::LinkedList(std::initializer_list<Type> init): head(nullptr), _size(0){

	for(const Type& item : init)
		push_back(item);

}

template <class Type>
Nlib::LinkedList<Type>::~LinkedList(void){

	clear();

}

template <class Type>
size_t Nlib::LinkedList<Type>::size(void) const{

	return _size;

}

template <class Type>
Nlib::ListNode<Type>* Nlib::LinkedList<Type>::at(int pos) const{

	if(pos < 0 || pos >= _size)
		return nullptr;

	Nlib::ListNode<Type>* curr = head;

	for(int i = 0; i < pos; curr = curr -> next, i++);

	return curr;

}

template <class Type>
Nlib::ListNode<Type>* Nlib::LinkedList<Type>::find(Type data) const{

	Nlib::ListNode<Type>* curr = head;

	for(; curr != nullptr && curr -> data != data; curr = curr -> next);

	return curr; // returns nullptr if the required node was not found

}

template <class Type>
bool Nlib::LinkedList<Type>::push_front(Type data){

	Nlib::ListNode<Type>* new_node = new Nlib::ListNode<Type>(data, head);

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	head = new_node;

	_size++;

	return true;

}

template <class Type>
bool Nlib::LinkedList<Type>::push_back(Type data){

	if(head == nullptr)
		return push_front(data);

	Nlib::ListNode<Type>* new_node = new Nlib::ListNode<Type>(data);

	// memory allocation failed
	if(new_node == nullptr)
		return false;
	
	Nlib::ListNode<Type>* tail = head;

	for(; tail -> next != nullptr; tail = tail -> next);

	tail -> next = new_node;

	_size++;

	return true;

}

template <class Type>
bool Nlib::LinkedList<Type>::insert(Type data, int pos){

	if(pos == 0)
		return push_front(data);

	Nlib::ListNode<Type>* prev = at(pos - 1);

	// position was not found
	if(prev == nullptr)
		return false;

	Nlib::ListNode<Type>* new_node = new Nlib::ListNode<Type>(data, prev -> next);

	// memory allocation failed
	if(new_node == nullptr)
		return false;

	prev -> next = new_node;

	_size++;

	return true;

}

template <class Type>
bool Nlib::LinkedList<Type>::remove(ListNode<Type>* node){

	if(node == nullptr)
		return false;
	
	Nlib::ListNode<Type>** indirect = &head;

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
bool Nlib::LinkedList<Type>::remove(int pos){

	return remove(at(pos));

}

template <class Type>
void Nlib::LinkedList<Type>::clear(void){

	Nlib::ListNode<Type>* prev = nullptr;

	Nlib::ListNode<Type>* curr = head;

	while(curr != nullptr){

		prev = curr;

		curr = curr -> next;

		delete prev;

	}

	head = nullptr;

	_size = 0;

}

template <class Type>
void Nlib::LinkedList<Type>::print(void) const{

	Nlib::ListNode<Type>* curr = head;

	std::cout << '[';

	while(curr != nullptr){

		std::cout << curr -> data;

		if((curr = curr -> next) != nullptr)
			std::cout << ", ";

	}

	std::cout << "]" << std::endl;

}

template <class Type>
Type& Nlib::LinkedList<Type>::operator[](int idx){

	ListNode<Type>* node = at(idx);

	if(node == nullptr)
		throw std::out_of_range("The given index was out of range of the linked list!");

	return node -> data;

}

template <class Type>
Type Nlib::LinkedList<Type>::operator[](int idx) const{

	ListNode<Type>* node = at(idx);

	if(node == nullptr)
		throw std::out_of_range("The given index was out of range of the linked list!");

	return node -> data;

}
