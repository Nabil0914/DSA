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

bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;

    while(second != NULL){
        if(first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Example 1: Palindrome list
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(2);
    head1->next->next->next = new Node(1);

    cout << "List 1: ";
    printList(head1);
    cout << "Is Palindrome? " << (isPalindrome(head1) ? "Yes" : "No") << endl;

    // Example 2: Not a Palindrome
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);

    cout << "\nList 2: ";
    printList(head2);
    cout << "Is Palindrome? " << (isPalindrome(head2) ? "Yes" : "No") << endl;

    return 0;
}