//Reverse Linked List (Recursive)

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

    Node* reverse(Node* head){
        if(head == NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        Node *rest= reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
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
 
    ll.head= ll.reverse(ll.head);  
 
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}