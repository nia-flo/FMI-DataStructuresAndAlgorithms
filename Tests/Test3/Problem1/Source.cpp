#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }


    void leaves(Node* root) {
        int sum = 0;
        std::cout << this->findSum(root) << '\n';
    }

private:

    int findSum(Node* node)
    {
        if (node->leftNode == NULL)
        {
            if (node->rightNode == NULL)
            {
                if (node->data % 2 == 1)
                {
                    return node->data;
                }
                else
                {
                    return 0;
                }
            }
            
            return findSum(node->rightNode);
        }

        if (node->rightNode == NULL)
        {
            return findSum(node->leftNode);
        }

        return findSum(node->leftNode) + findSum(node->rightNode);
    }

}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}