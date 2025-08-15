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

Node* reverseALL(Node* head){
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    // Creating linked list: 1 -> 2 -> 9 -> 4
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(9);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    head = reverseALL(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;

}