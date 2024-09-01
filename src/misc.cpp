#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;

// -- Miscellaneous functions
/*
    Frees up the memory of all tree and graph nodes
    I/P: Nodes vector
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
