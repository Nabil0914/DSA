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

Node* findTail(Node* temp, int k){
    int cnt = 1;

    while(temp != NULL){
        if(cnt == k){
            return temp;
        }
        cnt++;
        temp = temp->next;
    }

    return temp;
}

Node* rotateLL(Node* head, int k){
    if(head == NULL || k == 0){
        return head;
    }

    int len = 1;
    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
        len = len + 1;
    }

    if(k % len == 0){
        return head;
    }

    k = k % len;
    tail->next = head;

    Node* newTail = findTail(head, len - k);

    head = newTail->next;
    newTail->next = NULL;

    return head;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create example linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    cout << "Original List: ";
    printList(head);

    head = rotateLL(head, k);

    cout << "Rotated List by " << k << ": ";
    printList(head);

    return 0;
}