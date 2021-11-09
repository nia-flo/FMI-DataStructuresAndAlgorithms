#pragma once

#include "Node.h"

template<typename T>
class Dequeue
{
public:
	Dequeue();

	~Dequeue();

	void push_back(const T& element);
	void push_front(const T& element);
	void pop_front();
	void pop_back();
	T front() const;
	T back() const;
	bool isEmpty() const;

private:
	Node<T>* first;
	Node<T>* last;
};

template<typename T>
inline Dequeue<T>::Dequeue()
{
	this->first = nullptr;
	this->last = nullptr;
}

template<typename T>
inline Dequeue<T>::~Dequeue()
{
	while (this->first != nullptr)
	{
		Node<T>* toDelete = this->first;
		this->first = this->first->next;
		delete toDelete;
	}
}

template<typename T>
inline void Dequeue<T>::push_back(const T& element)
{
	if (this->first == nullptr)
	{
		this->first = new Node<T>(element);
		this->last = this->first;
		return;
	}

	this->last->next = new Node<T>(element, this->last, nullptr);
	this->last = this->last->next;
}

template<typename T>
inline void Dequeue<T>::push_front(const T& element)
{
	if (this->first == nullptr)
	{
		this->first = new Node<T>(element);
		this->last = this->first;
		return;
	}

	this->first->previous = new Node<T>(element, nullptr, this->first);
	this->first = this->first->previous;
}

template<typename T>
inline void Dequeue<T>::pop_front()
{
	if (this->first == nullptr)
	{
		return;
	}

	Node<T>* toDelete = this->first;

	this->first = this->first->next;
	if (this->first != nullptr)
	{
		this->first->previous = nullptr;
	}
	else
	{
		this->last = nullptr;
	}

	delete toDelete;
}

template<typename T>
inline void Dequeue<T>::pop_back()
{
	if (this->last == nullptr)
	{
		return;
	}

	Node<T>* toDelete = this->last;

	this->last = this->last->previous;
	if (this->last != nullptr)
	{
		this->last->next = nullptr;
	}
	else
	{
		this->first = nullptr;
	}

	delete toDelete;
}

template<typename T>
inline T Dequeue<T>::front() const
{
	return this->first->data;
}

template<typename T>
inline T Dequeue<T>::back() const
{
	return this->last->data;
}

template<typename T>
inline bool Dequeue<T>::isEmpty() const
{
	return this->first == nullptr;
}
