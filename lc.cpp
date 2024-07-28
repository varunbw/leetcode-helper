#include <bits/stdc++.h>
#include "include/mylib.h"

using namespace std;

class Solution {
public:


    
};

int main(int argc, char** argv) {

    cout << "\n";
    Solution sol;

    // vector<int> vec = argsParseInt_1D(argc, argv, 1);
    // print1DVector(vec);

    // vector<vector<int>> vec = argsParseInt_2D(argc, argv, 0);
    // print2DVector(vec);
    
    vector<string> vec = argsParseString_1D(argc, argv, 0);
    vector<TreeNode*> nodes;
    TreeNode* root = createBinaryTree(vec, nodes);
    

    
    
    
    
    
    
    
    
    
    deleteNodes(nodes);
    cout << "\n";
    return 0;
}