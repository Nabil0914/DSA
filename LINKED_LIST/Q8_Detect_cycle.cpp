#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

bool detectCycleLL(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main() {
    // create nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Case 1: no cycle
    cout << "Cycle? " << (detectCycleLL(head) ? "Yes" : "No") << endl;

    // Case 2: introduce a cycle (4 -> 2)
    head->next->next->next->next = head->next;

    cout << "Cycle? " << (detectCycleLL(head) ? "Yes" : "No") << endl;

    return 0;
}