#pragma once

#ifndef LCH_MISC_HPP
#define LCH_MISC_HPP

#include "text_colors.hpp"

using std::cout;

// -- Vector Printing
template <typename T>
void Print1DVector(const std::vector<T>& vec, std::ostream& stream = cout) {

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
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vec) {
    Print1DVector(vec, stream);
    return stream;
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

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<std::vector<T>>& vec) {
    Print2DVector(vec, stream);
    return stream;
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


/*
    @brief Asserts results to their expected values
    @param `value` Result of solution
    @param `expected` Expected output
    @param `stream` Custom stream to print to

    Be sure to pass the same data types to `value` and `expected`

    [WARNING]: As of now, it also outputs the value, and the expected result if the testcase fails.
    This works on vectors due to the overloaded operator `<<`.
    If you want it to work on other types that can't just be printed with `<<`, you'll need to
    explicitly overload the operators and make them print how you want it.
*/
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
    stream << value;

    if (testcasePassed == false) 
        stream << ", expected: " << expected;

    stream << '\n';
    return;
}


#endif