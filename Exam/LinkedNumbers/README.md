# Linked Numbers

Разполагате с 2 числа, представени чрез свързани списъци. Числата са обърнати наобратно. Намерете сумата на двете числа.

### Input Format

На първия ред на стандартния вход прочитате число L1 - дължината на първото число.

На втория ред следват L1 на брой едноцифрени числа, разделени с интервали - цифрите на първото число.

На третия ред на стандартния вход прочитате число L2 - дължината на второто число.

На последния ред следват L2 на брой едноцифрени числа, разделени с интервали - цифрите на второто число.

### Constraints

1 <= L1, L2 <= 4*10^6

### Output format

На единственият ред на стандартния изход изведете сумата на двете числа (в правилната посока)

### Sample Input 0

3 <br>
1 2 3 <br>
2 <br>
8 2

### Sample Output 0

349

### Explanation 0

321 + 28 = 349

### Clarification

Даден е следният код, който трябва да се допълни, така че да решава дадената задача:

```
#include <iostream>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    
private:
    Node *head, *tail;
};

void solve(LinkedList& num1, LinkedList& num2){
    // TODO: Implement this function
    // Feel free to modify the template to your liking
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
  
    solve(num1, num2);
}
```
