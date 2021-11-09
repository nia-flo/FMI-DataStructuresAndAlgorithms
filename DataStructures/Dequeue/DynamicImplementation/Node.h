#pragma once

template<typename T>
struct Node
{
	T data;
	Node* previous;
	Node* next;

	Node(const T& data);
	Node(const T& data, Node<T>* previous, Node<T>* next);
};

template<typename T>
inline Node<T>::Node(const T& data)
{
	this->data = data;
	this->previous = nullptr;
	this->next = nullptr;
}

template<typename T>
inline Node<T>::Node(const T& data, Node<T>* previous, Node<T>* next)
{
	this->data = data;
	this->previous = previous;
	this->next = next;
}