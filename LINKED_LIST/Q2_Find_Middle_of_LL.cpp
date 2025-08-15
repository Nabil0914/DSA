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

Node* findMiddleLL(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    // Creating linked list:
    Node* head = new Node(5);
    head->next = new Node(7);
    head->next->next = new Node(4);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(9);


    Node* mid = findMiddleLL(head);

    if (mid != NULL)
        cout << "Middle Node value: " << mid->data << endl;
    else
        cout << "List is empty." << endl;

    return 0;
}