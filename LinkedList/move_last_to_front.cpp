
/**
 * Program to move last element to front in a given linked list.
 * 
 * References: https://www.geeksforgeeks.org/move-last-element-to-front-of-a-given-linked-list/
 */

#include <bits/stdc++.h>
using namespace std;
  
/* A linked list node */
class Node { 
    public:
    int data; 
    Node *next; 
}; 
  
/* We are using a double pointer head here because we change 
head of the linked list inside this function.*/
Node* moveToFront(Node **head) { 
    if(*head == NULL || (*head)->next == NULL) return *head;
    Node *temp = *head, *curr = temp, *prev= NULL;
    while(curr->next != NULL){
        prev=curr;
        curr=curr->next;
    }
    prev->next=NULL;
    curr->next= *head;
    *head = curr;
} 
  
/* UTILITY FUNCTIONS */
/* Function to add a node 
at the beginning of Linked List */
void push(Node** head_ref, int new_data) { 
    Node* new_node = new Node();
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}  
  
/* Function to print nodes in a given linked list */
void printList(Node *node) { 
    while(node != NULL){ 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 

int main(){ 
    Node *start = NULL; 
  
    /* The constructed linked list is: 
    1->2->3->4->5 */
    push(&start, 5); 
    push(&start, 4); 
    push(&start, 3); 
    push(&start, 2); 
    push(&start, 1); 
  
    cout<<"Linked list before moving last to front\n"; 
    printList(start); 
  
    moveToFront(&start); 
  
    cout<<"\nLinked list after removing last to front\n"; 
    printList(start); 
  
    return 0; 
} 