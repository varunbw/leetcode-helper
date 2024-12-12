#include "../include/lch.h"

using std::cout;
using std::cerr;
using std::endl;

using std::string;
using std::vector;
using std::queue;

// -- Binary Tree
/*
    @brief Constructs a binary tree out of the given vector
    @param nodes The representation of nodes
    @return Root of tree

    Leetcode uses BFS to serialize binary trees into a string.
    ex:   1
         / \
        2   3
           / \
          4   5
    
    gets serialized into "[1,2,3,null,null,4,5]"

    * Check comment in source code for clearer visual representation
*/
TreeNode* CreateBinaryTree(const vector<string>& nodes) {

    if (nodes.empty() || nodes[0] == "null") {
        throw std::invalid_argument(
            RED_START +
            string("[ERROR] CreateBinaryTree(const std::vector<std::string>&): Empty vector passed as argument") +
            RESET_COLOR
        );
    }

    // Create the root node
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    allocatedTreeNodes.push_back(root);

    // Use a queue to build the tree level by level
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (q.empty() == false && i < nodes.size()) {

        TreeNode* curr = q.front();
        q.pop();

        // Process the left child
        if (nodes[i] != "null") {
            TreeNode* leftNode = new TreeNode(stoi(nodes[i]));
            allocatedTreeNodes.push_back(leftNode);
            curr->left = leftNode;
            q.push(leftNode);
        }
        i++;

        // Process the right child
        if (i < nodes.size() && nodes[i] != "null") {
            TreeNode* rightNode = new TreeNode(stoi(nodes[i]));
            allocatedTreeNodes.push_back(rightNode);
            curr->right = rightNode;
            q.push(rightNode);
        }
        i++;
    }

    return root;
}

/* 
    @brief Prints a preorder traversal of the given tree
    @param root Node to start from
*/
void PrintBinaryTree_Preorder(const TreeNode* root, std::ostream& stream) {
    
    if (root == nullptr) return;
    
    stream << root->val << "  ";
    PrintBinaryTree_Preorder(root->left , stream);
    PrintBinaryTree_Preorder(root->right, stream);

    return;
}



// ! Not used
// This is how a I thought a BT would be represented
// However, LeetCode uses a different codec, that uses BFS
// The above function works with the LC serialized format
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
/*
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
*/