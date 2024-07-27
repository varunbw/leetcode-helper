#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <bits/stdc++.h>
using namespace std;

// -- Input Parsing
vector<int> argsParseInt(int, char**, int);
vector<string> argsParseString(int, char**, int);


// -- Vector
template <typename T>
void print1DVector(vector<T> vec) {
    for (auto ele : vec)
        cout << ele << "  ";
    cout << "\n";
}

template <typename T>
void print2DVector(vector<vector<T>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}


// -- Linked List
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList();
void displayLinkedList(ListNode*);



// -- Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

TreeNode* createBinaryTree(vector<string>, vector<TreeNode*>&);
void deleteNodes(vector<TreeNode*>&);

#endif