#pragma once

#ifndef LCH_MISC_HPP
#define LCH_MISC_HPP

// -- Vector Printing
template <typename T>
void Print1DVector(std::vector<T> vec, std::ostream& stream = cout) {

    const int n = vec.size();

    stream << '[';
    
    if (n)
        stream << vec[0];
        
    for (int i = 1; i < n; i++)
        stream << ", " << vec[i];

    stream << "]\n";

    return;
}

template <typename T>
void Print2DVector(std::vector<std::vector<T>> vec, std::ostream& stream = cout) {

    const int rows = vec.size();

    stream << "[\n";
    for (int i = 0; i < rows; i++) {
        stream << "    [";
        
        if (vec[i].size())
            stream << vec[i][0];
            
        for (int j = 1; j < vec[i].size(); j++) 
            stream << ", " << vec[i][j];
        
        stream << "]\n";
    }
    stream << "]\n";
    
    return;
}



// -- General
// -- Miscellaneous functions
/*
    @brief Frees up the memory of all tree and graph nodes
    Containers referred:
    - inline std::vector<ListNode*> allocatedListNodes;
    - inline std::vector<TreeNode*> allocatedTreeNodes;
    - inline std::vector<GraphNode*> allocatedGraphNodes;
*/
void DeleteAllocatedNodes();

#endif