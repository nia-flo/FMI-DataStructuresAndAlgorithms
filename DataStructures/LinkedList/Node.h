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

//template<typename T>
//inline Node<T>& Node<T>::operator=(const Node<T>& other)
//{
//	this->data = other.data;
//	this->next = other.next;
//
//	return *this;
//}
