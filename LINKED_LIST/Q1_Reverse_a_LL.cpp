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

Node* reverseALLIterative(Node* head){
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

Node* reverseLLRecursive(Node* head){
    //Base Condition
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* newHead = reverseLLRecursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
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
    // head = reverseALLIterative(head);
    head = reverseLLRecursive(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;

}