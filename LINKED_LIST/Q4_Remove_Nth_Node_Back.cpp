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

Node* removeNthNodeFromBack(Node* head, int n){
    Node* slow = head;
    Node* fast = head;

    for(int i = 0; i<n; i++){
        fast = fast->next;
    }

    if(fast == NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* nodeToBeDeleted = slow->next;
    slow->next = slow->next->next;

    free(nodeToBeDeleted);

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    int n = 2; // Remove 2nd node from the end
    head = removeNthNodeFromBack(head, n);

    cout << "After removing " << n << "th node from back: ";
    printList(head);

    return 0;
}