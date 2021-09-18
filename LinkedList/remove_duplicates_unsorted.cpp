/** 
 * Remove duplicates from an unsorted linked list.
 * References: https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
*/

#include <bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};
 
struct Node *newNode(int data){
   Node *temp = new Node;
   temp->data = data;
   temp->next = NULL;
   return temp;
}

//Function to remove duplicates from unsorted linked list.
Node * removeDuplicates( Node *head) {
    unordered_set<int> s;
    Node *temp = head;
    Node *prev = NULL;
    while(temp!=NULL){
        if(s.find(temp->data)!=s.end()){
            prev->next= temp->next;
            free(temp);
        }
        else{
            s.insert(temp->data);
            prev=temp;
        }
        temp=prev->next;
    }
}
    
void printList(struct Node *node){
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next = newNode(11);
    start->next->next->next->next->next->next = newNode(10);
 
    printf("Linked list before removing duplicates : \n");
    printList(start);
 
    removeDuplicates(start);
 
    printf("\nLinked list after removing duplicates : \n");
    printList(start);
 
    return 0;
}


