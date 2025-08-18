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

Node* findStartNode(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Creating a cycle: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Node* cycleStart = findStartNode(head);

    if(cycleStart != NULL) {
        cout << "Cycle starts at node with value: " << cycleStart->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}