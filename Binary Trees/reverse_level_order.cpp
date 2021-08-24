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

void reverselevelOrder(Node* root){
    if(root==NULL) return;
    stack<Node*> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        s.push(root);
        if(root->right) q.push(root->right);
        if(root->left) q.push(root->left);
    }
    while(!s.empty()){
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
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
 
    cout << "Reverse Level Order traversal of binary tree is \n";
    reverselevelOrder(root);
    return 0;
}