//Print height(maximum depth) of a binary tree.

#include <bits/stdc++.h>
using namespace std;

int height(struct Node* node){
        if(node==NULL) return 0;
        else{
            int lheight = height(node->left);
            int rheight = height(node->right);
            if(lheight>rheight) return lheight+1;
            else return rheight+1;
    }
}

//Alternate one liner solution

// int height(Node* root) {
//         if(root==NULL) return 0;
//         return 1+max(maxDepth(root->left),maxDepth(root->right));
// }