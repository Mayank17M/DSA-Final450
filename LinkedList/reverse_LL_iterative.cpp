//Reverse Linked List (Iterative)

#include <bits/stdc++.h>
using namespace std;

class Node 
{ 
    public:
    int data; 
    Node *next; 
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class LinkedList{
    public:
    Node *head;
    LinkedList(){
        head = NULL;
    }

    void reverse(){
        Node* curr = head;
        Node* prev= NULL, *nxt= NULL;
        while(curr != NULL){
            nxt=curr->next;
            curr->next=prev;
            prev = curr;
            curr= nxt;
        }
        head=prev;
    }

    void print()
    {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}