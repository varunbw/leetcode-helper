#pragma once

#ifndef LCH_DATA_STRUCTURES_HPP
#define LCH_DATA_STRUCTURES_HPP

using std::cout;

// -- Linked List
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    Container to store dynamically allocated list nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline std::vector<ListNode*> allocatedListNodes;

/*
    @brief Does what it says
    @param vec Vector to convert to a linked list
    @return Head of linked list
*/
ListNode* CreateLinkedList(const std::vector<int>& nodes);

/*
    @brief Does what it says, prints to std::cout
    @param head Node to start printing from
*/
void PrintLinkedList(const ListNode* head, std::ostream& stream = cout);



// -- Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

/*
    Container to store dynamically allocated tree nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline std::vector<TreeNode*> allocatedTreeNodes;

/*
    @brief Constructs a binary tree out of the given std::vector
    @param nodes The representation of nodes
    @return Root of tree

    Leetcode uses BFS to serialize binary trees into a std::string.
    ex:   1
         / \
        2   3
           / \
          4   5
    
    gets serialized into "[1,2,3,null,null,4,5]"

    * Check comment in source code for clearer visual representation
*/
TreeNode* CreateBinaryTree(const std::vector<std::string>& nodes);

/* 
    @brief Prints a preorder traversal of the given tree
    @param root Node to start from
*/
void PrintBinaryTree_Preorder(const TreeNode* root, std::ostream& stream = cout);
void PrintBinaryTree_Inorder(const TreeNode* root, std::ostream& stream = cout);
void PrintBinaryTree_Postorder(const TreeNode* root, std::ostream& stream = cout);



// -- Graph
struct GraphNode {
    int val;
    std::vector<GraphNode*> neighbors;

    GraphNode() : val(0), neighbors(std::vector<GraphNode*>()) {}
    GraphNode(int _val) : val(_val), neighbors(std::vector<GraphNode*>()) {}
    GraphNode(int _val, std::vector<GraphNode*> _neighbours) : val(_val), neighbors(_neighbours) {}
};

/*
    Container to store dynamically allocated graph nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline std::vector<GraphNode*> allocatedGraphNodes;

/*
    @brief Creates a graph from the given edge list
    @param edges Adjacency list
    @return Root of graph

    Each std::vector<int> in edges is an edge between two nodes.
*/
GraphNode* CreateGraph(const std::vector<std::vector<int>>& edges);

/*
    @brief Driver for performing a DFS on the given graph
    @param root Node to start the DFS from
*/
void PrintGraph_DFS(const GraphNode* root, std::ostream& stream = cout);

/*
    @brief Actually performs the DFS
    @param node Node currently being visited
    @param visited Adjacency list
*/
void PrintGraph_DFS(const GraphNode* node, std::set<const GraphNode*>& visited, std::ostream& = cout);

#endif