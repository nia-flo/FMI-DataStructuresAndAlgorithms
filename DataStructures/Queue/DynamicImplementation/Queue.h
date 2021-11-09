#pragma once

#include "Node.h"

template<typename T>
class Queue
{
public:
	Queue();

	~Queue();

	void push_back(const T& element);
	void pop_front();
	T front() const;
	bool isEmpty() const;

private:
	Node<T>* first;
	Node<T>* last;
};

template<typename T>
inline Queue<T>::Queue()
{
	this->first = nullptr;
	this->last = nullptr;
}

template<typename T>
inline Queue<T>::~Queue()
{
	while (this->first != nullptr)
	{
		Node<T>* toDelete = this->first;
		this->first = this->first->next;
		delete toDelete;
	}
}

template<typename T>
inline void Queue<T>::push_back(const T& element)
{
	if (this->first == nullptr)
	{
		this->first = new Node<T>(element);
		this->last = this->first;
		return;
	}

	this->last->next = new Node<T>(element);
	this->last = this->last->next;
}

template<typename T>
inline void Queue<T>::pop_front()
{
	if (this->first == nullptr)
	{
		return;
	}

	Node<T>* toDelete = this->first;
	this->first = this->first->next;
	delete toDelete;
}

template<typename T>
inline T Queue<T>::front() const
{
	return this->first->data;
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return this->first == nullptr;
}
