#pragma once

template <typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;

	Node(const T& data);
};

template<typename T>
inline Node<T>::Node(const T& data)
{
	this->data = data;
	this->left = nullptr;
	this->right = nullptr;
}