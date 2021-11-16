#pragma once

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	static int maxNodesCount;

	int data;
	Node* parent;
	Node* left;
	Node* right;
	int K;

	Node(int data);
};

class BinarySearchTree
{
public:
	BinarySearchTree();

	~BinarySearchTree();

	void add(int element);
	void remove(int K); // removes the k-th maximal element
	void print() const;

private:
	Node* root;

	void addNode(Node* node);
	void deleteNode(const Node* node);
	Node* findK(int K, Node* node);
};

int main()
{
	int N, K;
	cin >> N >> K;

	BinarySearchTree tree;
	for (int i = 0; i < N; i++)
	{
		int element;
		cin >> element;

		tree.add(element);
	}

	tree.remove(K);

	tree.print();

	return 0;
}

int Node::maxNodesCount = 1;

inline Node::Node(int data)
{
	this->data = data;
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

inline BinarySearchTree::BinarySearchTree()
{
	this->root = nullptr;
}

inline BinarySearchTree::~BinarySearchTree()
{
	this->deleteNode(this->root);
}

inline void BinarySearchTree::add(int element)
{
	this->addNode(new Node(element));
}

inline void BinarySearchTree::remove(int K)
{
	Node* node = this->findK(K, this->root);

	if (node->right == nullptr)
	{
		if (node->left == nullptr)
		{
			if (node->parent->left == node)
			{
				node->parent->left = nullptr;
			}
			else
			{
				node->parent->right = nullptr;
			}

			delete node;
			return;
		}

		if (node->parent->left == node)
		{
			node->parent->left = node->left;
		}
		else
		{
			node->parent->right = node->left;
		}
		node->left->parent = node->parent;

		delete node;
		return;
	}

	if (node->left == nullptr)
	{
		if (node->parent->left == node)
		{
			node->parent->left = node->right;
		}
		else
		{
			node->parent->right = node->right;
		}
		node->right->parent = node->parent;

		delete node;
		return;
	}

	Node* replacement = node->right;

	while (replacement->left != nullptr)
	{
		replacement = replacement->left;
	}

	node->data = replacement->data;
	
	if (replacement->parent->left == replacement)
	{
		if (replacement->right == nullptr)
		{
			replacement->parent->left = nullptr;
		}
		else
		{
			replacement->parent->left = replacement->right;
		}
	}
	else
	{
		if (replacement->right == nullptr)
		{
			replacement->parent->right = nullptr;
		}
		else
		{
			replacement->parent->right = replacement->right;
		}
	}

	delete replacement;
}

inline void BinarySearchTree::print() const
{
	queue<Node*> toPrint;
	toPrint.push(this->root);

	while (!toPrint.empty())
	{
		Node* node = toPrint.front();
		toPrint.pop();

		cout << node->data << ' ';

		if (node->left != nullptr)
		{
			toPrint.push(node->left);
		}
		if (node->right != nullptr)
		{
			toPrint.push(node->right);
		}
	}

	cout << '\n';
}

inline void BinarySearchTree::deleteNode(const Node* node)
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

Node* BinarySearchTree::findK(int K, Node* node)
{
	if (node->right != nullptr)
	{
		Node* rightResult = this->findK(K, node->right);
		if (rightResult != nullptr)
		{
			return rightResult;
		}
	}

	node->K = Node::maxNodesCount;
	Node::maxNodesCount++;

	if (node->K == K)
	{
		return node;
	}

	if (node->left != nullptr)
	{
		Node* leftResult = this->findK(K, node->left);
		if (leftResult != nullptr)
		{
			return leftResult;
		}
	}

	return nullptr;
}

inline void BinarySearchTree::addNode(Node* node)
{
	if (this->root == nullptr)
	{
		this->root = node;
		return;
	}

	Node* currNode = this->root;

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
				node->parent = currNode;
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
				node->parent = currNode;
				currNode->right = node;
				return;
			}
		}
	}
}