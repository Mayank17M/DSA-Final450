#include<bits/stdc++.h>
using namespace std;
#define endl ("\n")
#define pi (3.141592653589)
#define mod 1e9+7
#define ll long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

struct Node
{
    int data;
    struct Node *left, *right;
};

void levelOrder(Node* root){
    if(root==NULL) return;
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Driver program to test above functions
int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    levelOrder(root);
    return 0;
}