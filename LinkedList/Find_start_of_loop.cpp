/** 
 * C++ program to return first node of loop.
 * 
 * References: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
 
// A utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}

Node *detectAndRemoveLoop(Node * head){

    /* If list is empty or has only one node without loop */
    if(head==NULL || head->next==NULL) return NULL;

    Node *slow = head, *fast = head;

    /* Check for loop */
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }

    /* If loop exist find the starting point */
    if(slow == fast){
        slow = head;    
        while(slow->next!=fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    else{
        return NULL;
    }
    return fast->next;
}

int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = detectAndRemoveLoop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
 
    return 0;
}