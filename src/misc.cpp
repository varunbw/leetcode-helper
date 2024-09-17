#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;

// -- Miscellaneous functions
/*
    @brief Frees up the memory of all tree and graph nodes
*/
void DeleteAllocatedNodes() {

    for (ListNode* node : allocatedListNodes)
        delete node;

    for (TreeNode* node : allocatedTreeNodes)
        delete node;

    for (GraphNode* node : allocatedGraphNodes)
        delete node;

    return;
}
