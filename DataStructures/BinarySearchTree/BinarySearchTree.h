#pragma once

#include "Node.h"

#include <iostream>

template <typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();

	~BinarySearchTree();

	void insert(const T& element);
	void remove(const T& element);
	bool search(const T& element) const;
	void print() const;

private:
	Node<T>* root;

	void addNode(Node<T>* node);
	void print(const Node<T>* node) const;
	void deleteNode(const Node<T>* node);
};

template<typename T>
inline BinarySearchTree<T>::BinarySearchTree()
{
	this->root = nullptr;
}

template<typename T>
inline BinarySearchTree<T>::~BinarySearchTree()
{
	this->deleteNode(this->root);
}

template<typename T>
inline void BinarySearchTree<T>::insert(const T& element)
{
	this->addNode(new Node<T>(element));
}

template<typename T>
inline void BinarySearchTree<T>::remove(const T& element)
{
	Node<T>* parent = nullptr;
	Node<T>* currNode = this->root;

	while (true)
	{
		if (currNode->data == element)
		{
			break;
		}
		else if (currNode->data > element)
		{
			if (currNode->left != nullptr)
			{
				parent = currNode;
				currNode = currNode->left;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (currNode->right != nullptr)
			{
				parent = currNode;
				currNode = currNode->right;
			}
			else
			{
				return;
			}
		}
	}

	if (parent != nullptr)
	{
		if (parent->left == currNode)
		{
			parent->left = nullptr;
		}
		else
		{
			parent->right = nullptr;
		}
	}
	else
	{
		this->root = nullptr;
	}

	if (currNode->left != nullptr)
	{
		this->addNode(currNode->left);
	}

	if (currNode->right != nullptr)
	{
		this->addNode(currNode->right);
	}

	delete currNode;
}

template<typename T>
inline bool BinarySearchTree<T>::search(const T& element) const
{
	Node<T>* currNode = this->root;

	while (true)
	{
		if (currNode->data == element)
		{
			return true;
		}
		else if (currNode->data > element)
		{
			if (currNode->left != nullptr)
			{
				currNode = currNode->left;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (currNode->right != nullptr)
			{
				currNode = currNode->right;
			}
			else
			{
				return false;
			}
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::print() const
{
	this->print(this->root);
	std::cout << '\n';
}

template<typename T>
inline void BinarySearchTree<T>::deleteNode(const Node<T>* node)
{
	if (node->left != nullptr)
	{
		this->deleteNode(node->left);
	}

	if (node->right != nullptr)
	{
		this->deleteNode(node->right);
	}

	delete node;
}

template<typename T>
inline void BinarySearchTree<T>::addNode(Node<T>* node)
{
	if (this->root == nullptr)
	{
		this->root = node;
		return;
	}

	Node<T>* currNode = this->root;

	while (true)
	{
		if (currNode->data > node->data)
		{
			if (currNode->left != nullptr)
			{
				currNode = currNode->left;
			}
			else
			{
				currNode->left = node;
				return;
			}
		}
		else
		{
			if (currNode->right != nullptr)
			{
				currNode = currNode->right;
			}
			else
			{
				currNode->right = node;
				return;
			}
		}
	}
}

template<typename T>
inline void BinarySearchTree<T>::print(const Node<T>* node) const
{
	if (node == nullptr)
	{
		return;
	}

	this->print(node->left);
	std::cout << node->data << ' ';
	this->print(node->right);
}