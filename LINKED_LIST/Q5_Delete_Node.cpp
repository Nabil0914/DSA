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

void deleteNode(Node* node){
    if(node->next == NULL){
        return;
    }
    else{
        node->data = node->next->data;
        node->next = node->next->next;
    }
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create Linked List: 4 -> 5 -> 1 -> 9
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);

    cout << "Original List: ";
    printList(head);

    // Suppose we want to delete node with value 5
    deleteNode(head->next); // passing pointer to node 5

    cout << "After deleting node 5: ";
    printList(head);

    return 0;
}