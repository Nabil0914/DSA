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

Node* reverseLL(Node* head){
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

Node* getKNodes(Node* temp, int k){
    k = k - 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }

    return temp;
}

Node* reverseKNodes(Node* head, int k){
    Node* temp = head;
    Node* prevNode = NULL;

    while(temp != NULL){
        Node* kNode = getKNodes(temp, k);

        if(kNode == NULL){
            if(prevNode){
                prevNode->next = temp;
                break;
            }
        }

        Node* nextNode = kNode->next;
        kNode->next = NULL;
        Node* newHead = reverseLL(temp);

        if(prevNode != NULL){
            prevNode->next = newHead;
        } else {
            head = newHead; // update head if this is the first group
        }

        prevNode = temp;
        temp = nextNode;
    }

    return head;
}

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Helper function to append node at the end
void insertAtTail(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(val);
}

// Main function
int main() {
    Node* head = NULL;

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
    for (int i = 1; i <= 8; i++) {
        insertAtTail(head, i);
    }

    cout << "Original List:\n";
    printList(head);

    int k = 4;
    head = reverseKNodes(head, k);

    cout << "\nList after reversing in groups of " << k << ":\n";
    printList(head);

    return 0;
}