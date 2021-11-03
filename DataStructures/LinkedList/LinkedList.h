#pragma once

#include "Node.h"

#include <ostream>

template<typename T>
class LinkedList
{
public:
	LinkedList();

	~LinkedList();

	void push_back(const T& element);
	void push_front(const T& element);
	void insert(int position, const T& element);
	void pop_front();
	void pop_back();
	void remove(int position);
	bool contains(const T& element) const;
	void reverse();

	LinkedList& operator=(const LinkedList<T>& other);

	template <typename T>
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& linkedList);

private:
	Node<T>* head;
	Node<T>* tail;

	void free();
};

template<typename T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	this->free();
}

template<typename T>
inline void LinkedList<T>::push_back(const T& element)
{
	Node<T>* newNode = new Node<T>(element);

	if (this->head == nullptr)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		this->tail->next = newNode;
		this->tail = this->tail->next;
	}
}

template<typename T>
inline void LinkedList<T>::push_front(const T& element)
{
	Node<T>* newNode = new Node<T>(element);

	if (this->head == nullptr)
	{
		this->head = newNode;
		this->tail = newNode;
	}
	else
	{
		newNode->next = this->head;
		this->head = newNode;
	}
}

template<typename T>
inline void LinkedList<T>::insert(int position, const T& element)
{
	if (position == 0)
	{
		this->push_front(element);
		return;
	}

	Node<T>* prevNode = this->head;
	for (int i = 1; i < position && prevNode->next != nullptr; i++)
	{
		prevNode = prevNode->next;
	}

	Node<T>* newNode = new Node<T>(element, prevNode->next);
	prevNode->next = newNode;

	if (this->tail == prevNode)
	{
		this->tail = newNode;
	}
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
	if (this->head == nullptr)
	{
		return;
	}

	if (this->head == this->tail)
	{
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		return;
	}

	Node<T>* newHead = this->head->next;
	delete this->head;
	this->head = newHead;

	if (this->head == nullptr)
	{
		this->tail = nullptr;
	}
}

template<typename T>
inline void LinkedList<T>::pop_back()
{
	if (this->head == nullptr)
	{
		return;
	}

	if (this->head == this->tail)
	{
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		return;
	}

	Node<T>* newTail = this->head;
	for (Node<T>* curr = this->head->next; curr != this->tail; curr = curr->next)
	{
		newTail = newTail->next;
	} 

	delete this->tail;
	this->tail = newTail;
	this->tail->next = nullptr;
}

template<typename T>
inline void LinkedList<T>::remove(int position)
{
	if (position == 0)
	{
		this->pop_front();
		return;
	}

	Node<T>* prevNode = this->head;
	for (int i = 1; i < position && prevNode->next != nullptr; i++)
	{
		prevNode = prevNode->next;
	}

	if (prevNode->next == nullptr)
	{
		return;
	}

	Node<T>* toDelete = prevNode->next;
	prevNode->next = toDelete->next;
	delete toDelete;

	if (this->tail == nullptr)
	{
		this->tail = prevNode;
	}
}

template<typename T>
inline bool LinkedList<T>::contains(const T& element) const
{
	for (Node<T>* curr = this->head; curr != nullptr; curr = curr->next)
	{
		if (curr->data == element)
		{
			return true;
		}
	}

	return false;
}

template<typename T>
inline void LinkedList<T>::reverse()
{
	LinkedList<T> newList;
	for (Node<T>* curr = this->head; curr != nullptr; curr = curr->next)
	{
		newList.push_front(curr->data);
	}

	(*this) = newList;
}

template<typename T>
inline LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
	this->free();

	for (Node<T>* curr = other.head; curr != nullptr; curr = curr->next)
	{
		this->push_back(curr->data);
	}

	return *this;
}

template<typename T>
inline void LinkedList<T>::free()
{
	Node<T>* curr = this->head; 
	while(curr != nullptr)
	{
		Node<T>* toDelete = curr;
		curr = curr->next;
		delete toDelete;
	}

	this->head = nullptr;
	this->tail = nullptr;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& linkedList)
{
	for (Node<T>* node = linkedList.head; node != nullptr; node = node->next)
	{
		stream << node->data << ' ';
	}
	stream << '\n';

	return stream;
}