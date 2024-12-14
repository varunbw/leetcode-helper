#include <bits/stdc++.h>
#include "include/lch.hpp"

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
    ofstream fout("output.txt");

    int t;
    fin >> t;
    while (fin.peek() == '\n')
        fin.ignore();

    while (t--) {
        // -- 1D int
        // vector<int> vec = FileParse_Int1D(fin);
        // Print1DVector(vec);

        // -- 2D int
        // vector<vector<int>> grid = FileParse_Int2D(fin);
        // Print2DVector(grid);

        // -- 1D string
        // vector<string> vec = FileParse_String1D(fin);
        // Print1DVector(vec);

        // -- 2D string
        // vector<vector<string>> grid = FileParse_String2D(fin);
        // Print2DVector(grid);

        // -- 1D char
        // vector<char> vec = FileParse_Char1D(fin);
        // Print1DVector(vec);

        // -- 2D char
        // vector<vector<char>> grid = FileParse_Char2D(fin);
        // Print2DVector(grid);

        // -- Linked List
        // vector<int> vec = FileParse_Int1D(fin);
        // ListNode* head = CreateLinkedList(vec);
        // PrintLinkedList(head);

        // -- Binary Tree
        // vector<string> vec = FileParse_String1D(fin);
        // TreeNode* root = CreateBinaryTree(vec);
        // PrintBinaryTree_Preorder(root);

        // -- Graph
        // vector<vector<int>> grid = FileParse_Int2D(fin);
        // GraphNode* root = CreateGraph(grid);
        // PrintGraph_DFS(root);
    }

    DeleteAllocatedNodes();
    cout << "\n";
    return 0;
}
