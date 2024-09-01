#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;

// -- Binary Tree
/*
    Create a binary tree with the given vector
    Follows the format
        Left child pos  = (2 * node pos) + 1
        Right child pos = (2 * node pos) + 2
    
    ex: [1, 2, 3, null, null, 4, 5]
          1
         / \
        2   3
           / \
          4   5
    
    I/P: Vector of strings containing node values
         "null" or "n" signifies no node at corresponding location
    O/P: Pointer to root node
*/
TreeNode* CreateBinaryTree(vector<string>& inp) {

    vector<TreeNode*> nodes;

    const int inpSize = inp.size();
    if (inpSize == 0) {
        cerr << "Cannot make tree, vector empty";
        exit(0);
    }

    // Push "null" values and normal values accordingly
    for (int i = 0; i < inpSize; i++) {
        if (inp[i] == "null" || inp[i] == "n") {
            nodes.push_back(nullptr);
            continue;
        }

        TreeNode* newNode = new TreeNode(stoi(inp[i]));

        nodes.push_back(newNode);
        allocatedTreeNodes.push_back(newNode);
    }

    // Link children
    for (int i = 0; i < inpSize/2; i++) {

        if (nodes[i] == nullptr) continue;

        int left  = (2 * i) + 1;
        int right = (2 * i) + 2;

        if (left  < inpSize) nodes[i]->left  = nodes[left];
        if (right < inpSize) nodes[i]->right = nodes[right];
    }

    return nodes[0];
}


void BT_PreorderTraversal(TreeNode* root) {
    
    if (root == nullptr) return;
    
    cout << root->val << ", ";
    BT_PreorderTraversal(root->left);
    BT_PreorderTraversal(root->right);

    return;
}