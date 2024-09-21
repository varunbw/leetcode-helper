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
    int leastInterval(vector<char>& tasks, int n) {

        int res = 0;
        
        vector<int> freq(26, 0);
        unordered_map<char, int> cooldown;
        for (char task : tasks) {
            freq[task - 'A']++;
            cooldown[task - 'A'] = 0;
        }
        
        int remaining = tasks.size();
        while (remaining > 0) {
            char currTask = -1;
            for (int i = 0; i < 26; i++) {
                if (cooldown[i] == 0 && freq[i] > 0) {
                    currTask = i;
                    break;
                }
            }

            res++;
            for (auto [task, cd] : cooldown) {
                if (cd > 0)
                    cd--;
            }

            if (currTask == -1) continue;

            cooldown[currTask] = n;
            freq[currTask]--;
            remaining--;
        }        
        
        return res;
    }
};


int main(int argc, char** argv) {

    cout << "\n";
    Solution sol;

    // -- 1D vec
    // vector<int> vec = ArgsParseInt_1D(argc, argv, 1);
    // Print1DVector(vec); cout << endl;

    // -- 2D vec
    // vector<vector<int>> grid = ArgsParseInt_2D(argc, argv, 1);
    // Print2DVector(grid); cout << endl;

    // -- String
    vector<string> vec = ArgsParseString_1D(argc, argv, 1);
    Print1DVector(vec);
    
    vector<char> newVec;
    for (string str : vec)
        newVec.push_back(str[0]);

    Print1DVector(newVec);
    
    // cout << sol.leastInterval(newVec, stoi(argv[1]));

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