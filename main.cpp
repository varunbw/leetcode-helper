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

    ifstream fin("input.txt");
    ifstream finExpected("expected.txt");
    int t;
    fin >> t;
    while (fin.peek() == '\n')
        fin.ignore();

    while (t--) {
        // -- 1D int
        // vector<int> vec = FileParse_Int1D(fin);
        // Print1DVector(vec); cout << "\n";

        // -- 2D int
        // vector<vector<int>> grid = FileParse_Int2D(fin);
        // Print2DVector(grid); cout << "\n";

        // -- 1D string
        // vector<string> vec = FileParse_String1D(fin);
        // Print1DVector(vec); cout << "\n";

        // -- 2D string
        // vector<vector<string>> grid = FileParse_String2D(fin);
        // Print2DVector(grid); cout << "\n";

        // -- Linked List
        // vector<int> vec = FileParse_Int1D(fin);
        // ListNode* head = CreateLinkedList(vec);
        // DisplayLinkedList(head); cout << "\n";

        // -- Binary Tree
        // vector<string> vec = FileParse_String1D(fin);
        // TreeNode* root = CreateBinaryTree(vec);
        // BT_PreorderTraversal(root);

        // -- Graph
        // vector<vector<int>> grid = FileParse_Int2D(fin);
        // GraphNode* root = CreateGraph(grid);
        // G_DFS(root);
    }

    DeleteAllocatedNodes();
    cout << "\n";
    return 0;
}
