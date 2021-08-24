//Construct BST from given preorder traversal

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* temp= new node();
    temp->data = data;
    temp->left=temp->right=NULL;
    return temp;
}

// A recursive function to construct
// BST from pre[]. preIndex is used
// to keep track of index in pre[].
node* constructUtil(int pre[], int* preIndex, int key, int min, int max, int size){
    // Base case
    if(*preIndex>=size) return NULL;
    node* root = NULL;

    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if(key>min && key<max){
        root = newNode(key);
        *preIndex = *preIndex + 1;

        if(*preIndex<size){
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = constructUtil(pre,preIndex,pre[*preIndex],min,key,size);
        }
        if(*preIndex<size){
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = constructUtil(pre,preIndex,pre[*preIndex],key,max,size);
        }
    }
    return root;
}


node* constructTree(int pre[], int n){
    int preIndex = 0;
    return constructUtil(pre, &preIndex, pre[0], INT_MIN, INT_MAX, n);
}

void printInorder(node* root){
    if(root==NULL) return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    int pre[]={ 10, 5, 1, 7, 40, 50 };
    int n= sizeof(pre)/sizeof(pre[0]);
    node* root = constructTree(pre,n);
    printInorder(root);
    
    return 0;
}