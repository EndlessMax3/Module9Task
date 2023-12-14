#pragma once
#include <iostream>
using std::cout;
using std::endl;
#ifndef _LIST_H_
#define _LIST_H_

template<class T>
class List {
	
private:
	template<class T1>
	class Node {
	public:
		T1* data;
		Node<T1>* next;
		Node(T1* _data) : data(_data), next(nullptr) {}
		virtual ~Node() { delete data; }
	};
	Node<T>* first;
	mutable Node<T>* pointer;
	Node<T>* last;

public:

	List() : first(nullptr), last(nullptr) {}

	bool isEmpty()
	{
		return first == nullptr;
	}

	void push_back(T* _data) 
	{
		Node<T>* p = new Node<T>(_data);
		if (isEmpty()) 
		{
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	void start() const
	{
		pointer = nullptr;
	}

	T* next() const
	{
		pointer = (pointer == nullptr) ? first : pointer->next;
		return (pointer == nullptr) ? nullptr : pointer->data;
	}

	void print() {
		if (isEmpty()) return;
		Node<T>* p = first;
		while (p) 
		{
			cout << *p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	void remove(const T& r)
	{
		Node<T>* p = first;
		Node<T>* prev = nullptr;
		while (p)
		{
			if (*(p->data) == r)
			{
				if (p == first && p == last)
					first = last = nullptr;
				else
				{
					if (p == first)
						first = p->next;
					if (prev != nullptr)
						prev->next = p->next;
				}
				delete p;
				return;
			}
			prev = p;
			p = p->next;
		}
		throw std::invalid_argument("Object for remove not found");
	}

	void clear()
	{
		Node<T>* p = first;
		while (p)
		{
			Node<T>* pNext = p->next;
			delete p;
			p = pNext;
		}
		first = last = pointer = 0;
	}
	
	virtual ~List()
	{
		clear();
	}
};

#endif // !_LIST_H_

