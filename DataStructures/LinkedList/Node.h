#pragma once

template<typename T>
struct Node
{
	T data;
	Node* next;

	Node(const T& data, Node<T>* next = nullptr);
};

template<typename T>
inline Node<T>::Node(const T& data, Node<T>* next)
{
	this->data = data;
	this->next = next;
}
