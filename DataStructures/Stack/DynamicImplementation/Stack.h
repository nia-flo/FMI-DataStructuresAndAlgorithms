#pragma once

#include "Node.h"

template<typename T>
class Stack
{
public:
	Stack();

	~Stack();

	void push(const T& element);
	void pop();
	T top() const;
	bool isEmpty() const;

private:
	Node<T>* topElement;
};

template<typename T>
inline Stack<T>::Stack()
{
	this->topElement = nullptr;
}

template<typename T>
inline Stack<T>::~Stack()
{
	while (this->topElement != nullptr)
	{
		Node<T>* toDelete = this->topElement;
		this->topElement = this->topElement->next;
		delete toDelete;
	}
}

template<typename T>
inline void Stack<T>::push(const T& element)
{
	if (this->topElement == nullptr)
	{
		this->topElement = new Node<T>(element);
		return;
	}

	this->topElement = new Node<T>(element, this->topElement);
}

template<typename T>
inline void Stack<T>::pop()
{
	if (this->topElement == nullptr)
	{
		return;
	}

	Node<T>* toDelete = this->topElement;
	this->topElement = this->topElement->next;
	delete toDelete;
}

template<typename T>
inline T Stack<T>::top() const
{
	return this->topElement->data;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return this->topElement == nullptr;
}
