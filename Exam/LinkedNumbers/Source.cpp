#include <iostream>

using namespace std;


struct Node {
    Node* next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    LinkedList(const LinkedList& other);
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    LinkedList& operator=(const LinkedList& other);

    LinkedList sumWith(const LinkedList& other) const;
    void reverse();
    void printNum() const;

private:
    Node* head, * tail;

    void copy(const LinkedList& other);
};

void solve(LinkedList& num1, LinkedList& num2) {
    LinkedList result = num1.sumWith(num2);
    result.reverse();
    result.printNum();

}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}

LinkedList::LinkedList(const LinkedList& other)
{
    this->copy(other);
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    this->copy(other);

    return *this;
}

LinkedList LinkedList::sumWith(const LinkedList& other) const
{
    LinkedList result;
    Node* digit1 = this->head;
    Node* digit2 = other.head;
    int addition = 0;

    while (digit1 != nullptr && digit2 != nullptr)
    {
        int currentSum = digit1->data + digit2->data + addition;
        addition = 0;
        if (currentSum > 9)
        {
            addition = currentSum / 10;
            currentSum %= 10;
        }

        result.add(currentSum);

        digit1 = digit1->next;
        digit2 = digit2->next;
    }

    while (digit1 != nullptr)
    {
        int currentSum = digit1->data + addition;
        addition = 0;
        if (currentSum > 9)
        {
            addition = currentSum / 10;
            currentSum %= 10;
        }

        result.add(currentSum);

        digit1 = digit1->next;
    }

    while (digit2 != nullptr)
    {
        int currentSum = digit2->data + addition;
        addition = 0;
        if (currentSum > 9)
        {
            addition = currentSum / 10;
            currentSum %= 10;
        }

        result.add(currentSum);

        digit2 = digit2->next;
    }

    if (addition != 0)
    {
        result.add(addition);
    }

    return result;
}

void LinkedList::reverse()
{
    Node* newTail = new Node;
    newTail->data = this->head->data;
    newTail->next = nullptr;

    Node* newHead = newTail;

    for (Node* curr = this->head->next; curr != nullptr; curr = curr->next)
    {
        Node* node = new Node;
        node->data = curr->data;
        node->next = newHead;

        newHead = node;
    }

    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    this->head = newHead;
    this->tail = newTail;
}

void LinkedList::printNum() const
{
    for (Node* curr = this->head; curr != nullptr; curr = curr->next)
    {
        cout << curr->data;
    }
    cout << '\n';
}

void LinkedList::copy(const LinkedList& other)
{
    this->head = nullptr;
    this->tail = nullptr;

    for (Node* curr = other.head; curr != nullptr; curr = curr->next)
    {
        this->add(curr->data);
    }
}
