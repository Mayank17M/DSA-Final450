/**
 * Print Left View of a Binary Tree
 * References: https://www.geeksforgeeks.org/print-left-view-binary-tree/
 */ 

#include<bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node{
    int data;
    struct Node *left, *right;
};
 
// Utility function to create a new tree node
Node* newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// function to print left view of
// binary tree
vector<int> leftView(Node *root){
    if(!root) return {};
    queue<Node*> q;
    vector<int> res;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            Node *temp = q.front();
            q.pop();
            if(i==1){
                res.push_back(temp->data);
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return res;
}
 
// Driver code
int main(){
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);

    vector<int> ans = leftView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
}