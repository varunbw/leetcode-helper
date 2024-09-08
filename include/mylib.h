#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <bits/stdc++.h>
using namespace std;



// -- Input Parsing
vector<int> ArgsParseInt_1D(const int, char**, const int);
vector<vector<int>> ArgsParseInt_2D(const int, char**, const int);
vector<string> ArgsParseString_1D(const int, char**, const int);



// -- Vector Printing
template <typename T>
void Print1DVector(vector<T> vec) {
    for (auto ele : vec)
        cout << ele << "  ";
    cout << "\n";

    return;
}

template <typename T>
void Print2DVector(vector<vector<T>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

    return;
}



// -- Linked List
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline vector<ListNode*> allocatedListNodes;

ListNode* CreateLinkedList();
void DisplayLinkedList(const ListNode*);



// -- Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

inline vector<TreeNode*> allocatedTreeNodes;

TreeNode* CreateBinaryTree(const vector<string>&);
void BT_PreorderTraversal(const TreeNode*);



// -- Graph
struct GraphNode {
    int val;
    vector<GraphNode*> neighbors;

    GraphNode() : val(0), neighbors(vector<GraphNode*>()) {}
    GraphNode(int _val) : val(_val), neighbors(vector<GraphNode*>()) {}
    GraphNode(int _val, vector<GraphNode*> _neighbours) : val(_val), neighbors(_neighbours) {}
};

inline vector<GraphNode*> allocatedGraphNodes;

GraphNode* CreateGraph(const vector<vector<int>>&);
void G_DFS(const GraphNode*);
void G_DFS(const GraphNode*, set<const GraphNode*>&);



// -- General
void DeleteAllocatedNodes();



#endif