/** 
 * Add two numbers represented by linked lists.
 * 
 * Reference: https://www.geeksforgeeks.org/sum-of-two-linked-lists/ 
 */

#include <bits/stdc++.h>
using namespace std;
   
// A linked List Node 
class Node{ 
    public:
    int data; 
    Node* next; 
};
 
// to push a new node to linked list
void push(Node** head_ref, int new_data){
    Node* new_node = new Node[(sizeof(Node))]; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}

struct Node* addTwoLists(struct Node* first, struct Node* second){
    stack<int> s1, s2;
    while(first!=NULL){
        s1.push(first->data);
        first=first->next;
    }
    while(second!=NULL){
        s2.push(second->data);
        second=second->next;
    }
    int carry = 0;
    Node *result=NULL;
    while(!s1.empty() || !s2.empty()){
        int a=0,b=0;
        if(!s1.empty()){
            a=s1.top();
            s1.pop();
        }
        if(!s2.empty()){
            b= s2.top();
            s2.pop();
        }
        int sum = a+b+carry;
        int x = sum%10;
        Node *temp = new Node();
        temp->data = sum%10;
        carry = sum/10;
        if(result==NULL){
            result = temp;
        }else{
            temp->next=result;
            result=temp;
        }
    }
    if(carry!=0){
        Node *temp= new Node();
        temp->data=carry;
        temp->next=result;
        result=temp;
    }
    return result;
}

// to print a linked list
void printList(Node *node){ 
    while (node != NULL) 
    { 
        cout<<node->data<<" "; 
        node = node->next; 
    } 
    cout<<endl; 
}
 
// Driver Code
int main(){ 
    Node *head1 = NULL, *head2 = NULL; 
   
    int arr1[] = {5, 6, 7}; 
    int arr2[] = {1, 8}; 
   
    int size1 = sizeof(arr1) / sizeof(arr1[0]); 
    int size2 = sizeof(arr2) / sizeof(arr2[0]); 
   
    // Create first list as 5->6->7 
    int i; 
    for (i = size1-1; i >= 0; --i) 
        push(&head1, arr1[i]); 
   
    // Create second list as 1->8 
    for (i = size2-1; i >= 0; --i) 
        push(&head2, arr2[i]); 
     
    Node* result=addTwoLists(head1, head2);
    printList(result); 
   
    return 0; 
}