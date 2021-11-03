#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* previous;
	Node* next;

	Node(int data);
};

class LinkedList
{
public:
	LinkedList();

	~LinkedList();

	void add(int data);
	void removeLast();
	void moveFrontToBack();
	void print() const;

private:
	Node* head;
	Node* middle;
	Node* tail;
	int elementsCount;
};

int main()
{
	int N;
	cin >> N;

	LinkedList list;
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;

		if (command == "add")
		{
			int data;
			cin >> data;

			list.add(data);
		}
		else if (command == "gun")
		{
			list.removeLast();
		}
		else
		{
			list.moveFrontToBack();
		}
	}

	list.print();

	return 0;
}

LinkedList::LinkedList()
{
	this->elementsCount = 0;
	this->head = nullptr;
	this->tail = nullptr;
	this->middle = nullptr;
}

LinkedList::~LinkedList()
{
	while (head != nullptr)
	{
		Node* toDelete = head;
		head = head->next;
		delete toDelete;
	}
}

void LinkedList::add(int data)
{
	elementsCount++;

	Node* newNode = new Node(data);

	if (head == nullptr)
	{
		head = newNode;
		tail = head;
		return;
	}

	tail->next = newNode;
	newNode->previous = tail;
	tail = newNode;

	if (head->next == nullptr)
	{
		head->next = tail;
	}

	if (elementsCount == 2)
	{
		middle = head;
	}
	else if (elementsCount > 2 && elementsCount % 2 == 1)
	{
		middle = middle->next;
	}
}

void LinkedList::removeLast()
{
	elementsCount--;

	Node* toDelete = this->tail;

	tail = tail->previous;

	if (tail == nullptr)
	{
		head = nullptr;
	}
	else
	{
		tail->next = nullptr;

		if (tail->previous == nullptr)
		{
			head = tail;
		}
	}

	if (elementsCount < 2)
	{
		middle = nullptr;
	}
	else  if (elementsCount % 2 == 0)
	{
		middle = middle->previous;
	}

	delete toDelete;
}

void LinkedList::moveFrontToBack()
{
	if (elementsCount < 2)
	{
		return;
	}

	Node* newHead;
	if (elementsCount % 2 == 1)
	{
		newHead = middle;
		middle = tail;
	}
	else
	{
		newHead = middle->next;
		middle = tail;
	}

	tail->next = this->head;
	this->head->previous = this->tail;

	this->tail = newHead->previous;
	this->tail->next = nullptr;

	this->head = newHead;
	this->head->previous = nullptr;
}

void LinkedList::print() const
{
	cout << this->elementsCount << '\n';
	for (Node* curr = this->head; curr != nullptr; curr = curr->next)
	{
		cout << curr->data << ' ';
	}
	cout << '\n';
}

Node::Node(int data)
{
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}
