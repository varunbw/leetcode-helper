#include <bits/stdc++.h>
#include "include/lch.h"

using namespace std;

static const int fastIO = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();


class Solution {
public:

};


int main(int argc, char** argv) {

    cout << endl;
    Solution sol;

    ifstream inp("input.txt");
    int t;
    inp >> t;

    while (t--) {
        vector<int> vec = ParseVector1D(inp);
        Print1DVector(vec);
    }

    // -- 1D vec
    // vector<int> vec = ArgsParseInt_1D(argc, argv, 0);
    // Print1DVector(vec); cout << endl;
    
    // vector<int> vec1 = ArgsParseInt_1D(argc, argv, 1);
    // Print1DVector(vec1); cout << endl;

    // -- 2D vec
    // vector<vector<int>> grid = ArgsParseInt_2D(argc, argv, 0);
    // Print2DVector(grid); cout << endl;

    // vector<vector<char>> gridChar(grid.size(), vector<char>(grid[0].size(), 0));
    // for (int i = 0; i < grid.size(); i++)
    //     for (int j = 0; j < grid[0].size(); j++)
    //         gridChar[i][j] = grid[i][j] + '0';

    // -- String
    // vector<string> vec = ArgsParseString_1D(argc, argv, 0);
    // Print1DVector(vec);

    // vector<char> newVec;
    // for (string str : vec)
    //     newVec.push_back(str[0]);

    // -- Linked List
    // vector<int> vec = ArgsParseInt_1D(argc, argv, 0);
    // ListNode* head = CreateLinkedList(vec);
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
