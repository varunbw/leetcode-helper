#pragma once

#ifndef LCH_MISC_HPP
#define LCH_MISC_HPP

#include "text_colors.hpp"

using std::cout;

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



// -- Miscellaneous functions
/*
    @brief Frees up the memory of all tree and graph nodes
    Containers referred:
    - inline std::vector<ListNode*> allocatedListNodes;
    - inline std::vector<TreeNode*> allocatedTreeNodes;
    - inline std::vector<GraphNode*> allocatedGraphNodes;
*/
void DeleteAllocatedNodes();


template <typename T>
void AssertTestcase(T value, T expected, std::ostream& stream = cout) {

    static int testcaseIdx = 1;
    stream << "#" << YELLOW_START << testcaseIdx++  << RESET_COLOR << " ";
    
    bool testcasePassed = true;
    // Print whether it passed or failed
    if (value == expected)
        stream << GREEN_START << "Pass: " << RESET_COLOR;
    else  {
        stream << RED_START << "Fail: " << RESET_COLOR;
        testcasePassed = false;
    }

    // Print the value
    using std::is_same_v;
    if constexpr (is_same_v<T, int> ||
                  is_same_v<T, float> || is_same_v<T, double> ||
                  is_same_v<T, std::string>) {

        stream << value;

        if (testcasePassed == false) {
            stream << ", expected: " << expected;
        }
    }
    else if constexpr (std::is_same_v<T, std::vector<typename T::value_type>>) {
        Print1DVector(value, stream);

        if (testcasePassed == false) {
            stream << ", expected: ";
            Print1DVector(expected);
        }
    }
    else {
        throw std::invalid_argument(
            RED_START +
            std::string("[ERROR] AssertTestcase(T, T): Given value of type T is not supported yet") +
            RESET_COLOR
        );
    }

    stream << '\n';
    return;
}


#endif