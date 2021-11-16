#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define ROOT 0

using namespace std;

struct Coordinates
{
	int x;
	int y;

	Coordinates();
	Coordinates(int x, int y);
};

struct Node
{
	int index;
	Node* left;
	Node* right;
	Coordinates coordinates;

	Node();
};

class Tree
{
public:
	Tree(int elementsCount);

	void add(int index, int leftIndex, int rightIndex);
	vector<int> findTopView();

private:
	vector<Node> elements;

	void findCoordinates(Node* node);
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	Tree tree(N);
	for (int i = 0; i < N; i++)
	{
		int leftIndex, rightIndex;
		cin >> leftIndex >> rightIndex;

		tree.add(i, leftIndex, rightIndex);
	}

	vector<int> topView = tree.findTopView();

	for (int i = 0; i < topView.size(); i++)
	{
		cout << topView[i] << ' ';
	}
	cout << '\n';

	return 0;
}

Node::Node()
{
	this->left = nullptr;
	this->right = nullptr;
}

Tree::Tree(int elementsCount)
{
	this->elements.resize(elementsCount);
}

void Tree::add(int index, int leftIndex, int rightIndex)
{
	this->elements[index].index = index;

	if (leftIndex != -1)
	{
		this->elements[index].left = &(this->elements[leftIndex]);
	}

	if (rightIndex != -1)
	{
		this->elements[index].right = &(this->elements[rightIndex]);
	}
}

vector<int> Tree::findTopView()
{
	this->findCoordinates(&(this->elements[0]));

	map<int, Node*> yOfUsedPointWithThisX;

	queue<Node*> nextNodes;
	nextNodes.push(&(this->elements[0]));

	while (!nextNodes.empty())
	{
		Node* currNode = nextNodes.front();
		nextNodes.pop();

		bool a = yOfUsedPointWithThisX.find(currNode->coordinates.x) == yOfUsedPointWithThisX.end();

		if (yOfUsedPointWithThisX.find(currNode->coordinates.x) == yOfUsedPointWithThisX.end() 
			|| yOfUsedPointWithThisX[currNode->coordinates.x]->coordinates.y < currNode->coordinates.y)
		{
			yOfUsedPointWithThisX[currNode->coordinates.x] = currNode;
		}

		if (currNode->left != nullptr)
		{
			nextNodes.push(currNode->left);
		}
		
		if (currNode->right != nullptr)
		{
			nextNodes.push(currNode->right);
		}
	}

	vector<int> topView;
	for (map<int, Node*>::iterator it = yOfUsedPointWithThisX.begin(); it != yOfUsedPointWithThisX.end(); it++)
	{
		topView.push_back(it->second->index);
	}

	return topView;
}

void Tree::findCoordinates(Node* node)
{
	if (node->left != nullptr)
	{
		node->left->coordinates = Coordinates(node->coordinates.x - 1, node->coordinates.y - 1);
		this->findCoordinates(node->left);
	}

	if (node->right != nullptr)
	{
		node->right->coordinates = Coordinates(node->coordinates.x + 1, node->coordinates.y - 1);
		this->findCoordinates(node->right);
	}
}

Coordinates::Coordinates() {
	this->x = 0;
	this->y = 0;
}

Coordinates::Coordinates(int x, int y)
{
	this->x = x;
	this->y = y;
}
