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

Node* findIntersection(Node* head1, Node* head2){
    if(head1 == NULL || head2 == NULL){
        return NULL;
    }

    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != temp2){
        temp1 = (temp1 == NULL) ? head2 : temp1->next;
        temp2 = (temp2 == NULL) ? head1 : temp2->next;
    }

    return temp1;
}
int main(){


// Create two linked lists:
    // List1: 1 -> 2 -> 3
    //                     \
    //                      6 -> 7
    //                     /
    // List2:       4 -> 5
    
    Node* common = new Node(6);
    common->next = new Node(7);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = common;

    Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}