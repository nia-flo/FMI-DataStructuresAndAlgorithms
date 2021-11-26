#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    int index;
    Node* left;
    Node* right;

    Node(int data, int index);
};

class BinarySearchTree
{
public:
    BinarySearchTree();

    ~BinarySearchTree();

    Node* add(int element, int index);
    int findMaxIndex(Node* node, int maxDifference);

private:
    Node* root;

    void addNode(Node*& node);
    void deleteNode(const Node* node);
    int findMaxIndex(Node* current, Node* node, int maxDifference);
};

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    BinarySearchTree tree;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;

        Node* node = tree.add(element, i);

        cout << tree.findMaxIndex(node, k) << ' ';
    }
    cout << '\n';

    return 0;
}

Node::Node(int data, int index)
{
    this->data = data;
    this->index = index;
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

inline Node* BinarySearchTree::add(int element, int index)
{
    Node* newNode = new Node(element, index);
    this->addNode(newNode);

    return newNode;
}

inline int BinarySearchTree::findMaxIndex(Node* node, int maxDifference)
{
    if (node->index == 0)
    {
        return -1;
    }

    return this->findMaxIndex(this->root, node, maxDifference);
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

int BinarySearchTree::findMaxIndex(Node* current, Node* node, int maxDifference)
{
    if (current == nullptr)
    {
        return -1;
    }

    int currentResult = -1;
    if (current->data < node->data && node->data - current->data <= maxDifference)
    {
        currentResult = current->index;
    }

    int leftResult = -1;
    if (current->left != nullptr && (current->data >= node->data || node->data - current->data <= maxDifference))
    {
        leftResult = this->findMaxIndex(current->left, node, maxDifference);
    }

    int rightResult = -1;
    if (current->right != nullptr && (current->data < node->data || node->data - current->data > maxDifference))
    {
        rightResult = this->findMaxIndex(current->right, node, maxDifference);
    }

    if (currentResult > leftResult)
    {
        if (currentResult > rightResult)
        {
            return currentResult;
        }

        return rightResult;
    }

    if (leftResult > rightResult)
    {
        return leftResult;
    }

    return rightResult;
}

inline void BinarySearchTree::addNode(Node*& node)
{
    if (this->root == nullptr)
    {
        this->root = node;
        return;
    }

    Node* currNode = this->root;

    while (true)
    {
        if (currNode->data == node->data)
        {
            currNode->index = node->index;
            delete node;
            node = currNode;
            return;
        }
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