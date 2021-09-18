/** 
 * Remove duplicates from a sorted linked list
 * References: https://www.geeksforgeeks.org/remove-duplicates-from-a-sorted-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node {
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
 
/* Function to insert a node at
   the beginning of the linked
 * list */
void push(Node** head_ref, int new_data){

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(Node* node){
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
 
// Function to remove duplicates
void removeDuplicates(Node* head){
    if(head == NULL) return;
    Node* curr = head;
    Node *nxt = head;
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            nxt = curr->next->next;
            free(curr->next);
            curr->next= nxt;
        }
        else curr= curr->next;
    }
}
 
// Driver Code
int main(){
    Node* head = NULL;
 
    /* Created linked list will be
    11->11->11->13->13->20 */
    push(&head, 20);
    push(&head, 13);
    push(&head, 13);
    push(&head, 11);
    push(&head, 11);
    push(&head, 11);
 
    cout << "Linked list before duplicate removal ";
    printList(head);
    cout << "\nLinked list after duplicate removal ";
    removeDuplicates(head);
    printList(head);
 
    return 0;
}