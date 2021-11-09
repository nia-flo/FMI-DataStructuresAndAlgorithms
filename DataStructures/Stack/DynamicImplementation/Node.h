#pragma once

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T& data, Node<T>* previous = nullptr);
};

template<typename T>
inline Node<T>::Node(const T& data, Node<T>* previous)
{
	this->data = data;
	this->next = previous;
}