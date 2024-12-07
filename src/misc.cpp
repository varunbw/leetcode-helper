#include "../include/lch.h"

// -- Miscellaneous functions
/*
    @brief Frees up the memory of all tree and graph nodes.

    Containers referred:
    
    - inline vector<ListNode*> allocatedListNodes;
    
    - inline vector<TreeNode*> allocatedTreeNodes;
    
    - inline vector<GraphNode*> allocatedGraphNodes;
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
