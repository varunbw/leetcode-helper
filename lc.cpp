#include <bits/stdc++.h>
#include "include/mylib.h"

using namespace std;

static const int fastIO = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();


class Solution {
public:


};


int main(int argc, char** argv) {

    cout << "\n";
    Solution sol;

    // -- 1D vec
    // vector<int> vec = ArgsParseInt_1D(argc, argv, 0);
    // Print1DVector(vec); cout << endl;

    // -- 2D vec
    // vector<vector<int>> grid = ArgsParseInt_2D(argc, argv, 0);
    // Print2DVector(grid);

    // -- String
    // vector<string> vec = ArgsParseString_1D(argc, argv, 0);
    // Print1DVector(vec);


    // -- Linked List
    // ListNode* head = CreateLinkedList();
    // DisplayLinkedList(head); cout << endl;

    // -- Binary Tree
    // vector<string> vec = ArgsParseString_1D(argc, argv, 0);
    // TreeNode* root = CreateBinaryTree(vec);
    // BT_PreorderTraversal(root); cout << endl;

    // -- Graph
    // GraphNode* root = CreateGraph(grid);
    // G_DFS(root);


    DeleteAllocatedNodes();
    cout << "\n";
    return 0;
}