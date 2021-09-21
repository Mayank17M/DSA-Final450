/**
 * How to determine if a binary tree is height-balanced?
 * References: https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/
 */ 

#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node {
public:
    int data;
    node* left;
    node* right;
};

/* Helper function that allocates
a new node with the given data
and NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}
// Function to calculate height of tree.
int height(node* root){
        if(root==NULL) return 0;
        return 1+ max(height(root->left), height(root->right));
    }

// Function to check whether the tree is balanced or not.
bool isBalanced(node *root)
{
    if(root==NULL) return true;
    if(!root->left && !root->right) return true;
    int lheight= height(root->left);
    int rheight= height(root->right);
    int flag;
    abs(lheight-rheight)<=1 && isBalanced(root->left) && isBalanced(root->right) ? flag=1 : flag=0;
    if(flag == 1) return true;
    else return false;
}
 
// Driver code
int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->left = newNode(8);
 
    if (isBalanced(root))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";
    return 0;
}