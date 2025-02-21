#include "../include/lch.hpp"

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
    
    if (root == nullptr)
        return;
    
    stream << root->val << "  ";
    PrintBinaryTree_Preorder(root->left , stream);
    PrintBinaryTree_Preorder(root->right, stream);

    return;
}

/* 
    @brief Prints an inorder traversal of the given tree
    @param root Node to start from
*/
void PrintBinaryTree_Inorder(const TreeNode* root, std::ostream& stream) {
    
    if (root == nullptr)
        return;
    
    PrintBinaryTree_Inorder(root->left , stream);
    stream << root->val << "  ";
    PrintBinaryTree_Inorder(root->right, stream);

    return;
}

/* 
    @brief Prints a postorder traversal of the given tree
    @param root Node to start from
*/
void PrintBinaryTree_Postorder(const TreeNode* root, std::ostream& stream) {
    
    if (root == nullptr)
        return;
    
    PrintBinaryTree_Postorder(root->left , stream);
    PrintBinaryTree_Postorder(root->right, stream);
    stream << root->val << "  ";

    return;
}