#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

namespace ll{

	template <class Type>
	class ListNode{

		template <class> friend class LinkedList;

	protected:
		Type data;

		ListNode* next;

	public:
		Type getData(void);

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

		size_t size(void);

		ListNode<Type>* getAt(unsigned int pos);

		ListNode<Type>* find(Type data);

		bool push_front(Type data);

		bool push_back(Type data);

		bool insert(Type data, unsigned int pos);

		bool remove(ListNode<Type>* node);

		bool remove(unsigned int pos);

		void clear(void);

		void print(void);

	};

};

#include "../src/linked_list.tpp"

#endif
