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

Node* merge2SortedLL(Node* head1, Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;

    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(t1 != NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        } 
        else {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }

    // Attache the remaining part of the first linked list if t1 is not finished yet.
    if(t1 != NULL){
        temp->next = t1;
    }

    else {
        temp->next = t2;
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
    // First sorted LL: 1 -> 3 -> 5 -> 7
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);


    // Second sorted LL: 2 -> 4 -> 6
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);


    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* merged = merge2SortedLL(head1, head2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}