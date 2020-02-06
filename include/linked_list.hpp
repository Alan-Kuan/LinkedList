#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <stdexcept>

namespace ll{

	template <class Type>
	class ListNode{

		template <class> friend class LinkedList;

	protected:
		Type data;

		ListNode* next;

	public:
		Type getData(void) const;

		void setData(Type data);

	};

	template <class Type>
	class LinkedList{

	protected:
		ListNode<Type>* head;

		size_t _size;

	public:
		LinkedList(void);

		~LinkedList(void);

		size_t size(void) const;

		ListNode<Type>* at(int pos) const;

		ListNode<Type>* find(Type data) const;

		bool push_front(Type data);

		bool push_back(Type data);

		bool insert(Type data, int pos);

		bool remove(ListNode<Type>* node);

		bool remove(int pos);

		void clear(void);

		void print(void) const;
		
		Type& operator[](int idx);

		Type operator[](int idx) const;

	};

};

#include "../src/linked_list.tpp"

#endif
