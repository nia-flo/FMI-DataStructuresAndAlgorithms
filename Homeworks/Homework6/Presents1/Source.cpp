#include <iostream>
#include <vector>
#include <queue>

#define ROOT 0

using namespace std;

struct Node
{
    int data;
    vector<Node*> children;

    Node(int data);
};

class Tree
{
public:
    Tree(int N);

    ~Tree();

    void add(const vector<int>* children, int childrenCount, vector<Node*> nodes);
    void printChildrenCount();

private:
    Node* root;
    vector<int> allChildrenCount;

    void deleteNode(const Node* node);
    int childrenCount(Node* node);
};

int main()
{
    int N;
    cin >> N;

    vector<int>* children = new vector<int>[N];
    for (int i = 0; i < N - 1; i++)
    {
        int boss, worker;
        cin >> boss >> worker;

        children[boss].push_back(worker);
    }

    Tree company(N);
    company.add(children, N, vector<Node*>(N));

    company.printChildrenCount();

    delete[] children;

    return 0;
}

Node::Node(int data)
{
    this->data = data;
}

Tree::Tree(int N)
{
    this->root = nullptr;
    this->allChildrenCount.resize(N, -1);
}

Tree::~Tree()
{
    this->deleteNode(this->root);
}

void Tree::add(const vector<int>* children, int childrenCount, vector<Node*> nodes)
{
    queue<int> indexesToAdd;
    indexesToAdd.push(0);
    nodes[0] = new Node(0);
    this->root = nodes[0];

    while (!indexesToAdd.empty())
    {
        int index = indexesToAdd.front();
        indexesToAdd.pop();

        for (int i = 0; i < children[index].size(); i++)
        {
            indexesToAdd.push(children[index][i]);
            nodes[children[index][i]] = new Node(children[index][i]);
            nodes[index]->children.push_back(nodes[children[index][i]]);
        }
    }
}

void Tree::printChildrenCount()
{
    this->childrenCount(this->root);

    for (int i = 0; i < this->allChildrenCount.size(); i++)
    {
        cout << this->allChildrenCount[i] << ' ';
    }
    cout << '\n';
}

void Tree::deleteNode(const Node* node)
{
    if (node == nullptr)
    {
        return;
    }

    for (int i = 0; i < node->children.size(); i++)
    {
        this->deleteNode(node->children[i]);
    }

    delete node;
}

int Tree::childrenCount(Node* node)
{
    if (this->allChildrenCount[node->data] == -1)
    {
        if (node->children.empty())
        {
            this->allChildrenCount[node->data] = 0;
        }

        this->allChildrenCount[node->data] = node->children.size();

        for (int i = 0; i < node->children.size(); i++)
        {
            this->allChildrenCount[node->data] += this->childrenCount(node->children[i]);
        }
    }

    return this->allChildrenCount[node->data];
}
