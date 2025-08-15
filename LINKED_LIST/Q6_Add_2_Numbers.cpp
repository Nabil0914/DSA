#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* addTwoNumbers(Node* num1, Node* num2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;

    while(temp1 != NULL && temp2 != NULL){
        int sum = carry;

        if(temp1){
            sum += temp1->data;
        }
        
        if(temp2){
            sum += temp2->data;
        }

        Node* newNode = new Node(sum % 10);
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1){
            temp1 = temp1->next;
        }

        if(temp2){
            temp2 = temp2->next;
        }
    }

    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }

    return dummyNode->next;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Number 1: 642 (stored as 2 -> 4 -> 6)
    Node* num1 = new Node(2);
    num1->next = new Node(4);
    num1->next->next = new Node(6);

    // Number 2: 783 (stored as 3 -> 8 -> 7 )
    Node* num2 = new Node(3);
    num2->next = new Node(8);
    num2->next->next = new Node(7);

    cout << "Number 1: ";
    printList(num1);

    cout << "Number 2: ";
    printList(num2);

    Node* result = addTwoNumbers(num1, num2);

    cout << "Sum: ";
    printList(result);

    return 0;
}