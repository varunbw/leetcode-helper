#ifndef LCH_LIBRARY
#define LCH_LIBRARY

#include <bits/stdc++.h>
#include "text_colors.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// -- Input Parsing - Through input file stream
/*
    @brief Parse inputs into a std::vector<int> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<int>

    This works with the following format only:
        [1,2,3,4,...]
*/
std::vector<int> FileParse_Int1D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::vector<int>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::vector<int>>

    This works with the following format only:
        [[1,2,3,4,...],[5,6,7,8,...],...]

    IMPORTANT: Keep the entire 2D grid in one line as seen above, don't split the rows into different lines
*/
std::vector<std::vector<int>> FileParse_Int2D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::string> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::string>

    This works with the following formats only:
        ["Hello","World"]
        [Hello,World]
*/
std::vector<std::string> FileParse_String1D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::vector<std::string>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::vector<std::string>>

    This works with the following format only:
        [["Hello","World"],["This is ", "a test :)"]]

    IMPORTANT: Keep the entire 2D grid in one line as seen above, don't split the rows into different lines
*/
std::vector<std::vector<std::string>> FileParse_String2D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<char> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<char>

    This works with the following formats
        ["a","b","c","d","e"]
        ['a','b','c','d','e']
        [a,b,c,d,e]
        a,b,c,d,e

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats
*/
std::vector<char> FileParse_Char1D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::vector<char>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::vector<char>>

    This works with the following formats
        [["a","b","c","d","e"],['a','b','c','d','e']]
        [[a,b,c,d,e],[a,b,c,d,e]]

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats
    IMPORTANT: Keep the entire 2D grid in one line as seen above, don't split the rows into different lines
*/
std::vector<std::vector<char>> FileParse_Char2D(std::ifstream& fin);



// -- Input Parsing - Through command line arguments
// These aren't really ideal, use the file parsers above
/*
    @brief Parse inputs as ints from the command line, and put them in a std::vector<int>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in std::vector<int> format

    This works on space separated numbers as well as
    a single argument as follows [1,2,3,4]
*/
std::vector<int> ArgsParse_Int1D(const int argc, char** argv, const int offset);

/*
    @brief Parse inputs as ints from the command line, and put them in a std::vector<std::vector<int>>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in std::vector<std::vector<int>> format

    This works with the following format only:
        [[1,2,3],[4,5,6],[7,8,9]].

    The above argument is a single std::string
*/
std::vector<std::vector<int>> ArgsParse_Int2D(const int argc, char** argv, const int offset);

/*
    @brief Parse inputs as ints from the command line, and put them in a std::vector<std::string>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in std::vector<std::string> format

    Works on space separated values as well as a single value like this ["hello world","checking","1234"]
*/
std::vector<std::string> ArgsParse_String1D(const int argc, char** argv, const int offset);



// -- Vector Printing
template <typename T>
void Print1DVector(std::vector<T> vec) {
    for (auto ele : vec)
        cout << ele << "  ";
    cout << "\n";

    return;
}

template <typename T>
void Print2DVector(std::vector<std::vector<T>> vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}



// -- Linked List
struct ListNode {
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    Container to store dynamically allocated list nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline std::vector<ListNode*> allocatedListNodes;

/*
    @brief Does what it says
    @param vec Vector to convert to a linked list
    @return Head of linked list
*/
ListNode* CreateLinkedList(const std::vector<int>& nodes);

/*
    @brief Does what it says, prints to std::cout
    @param head Node to start printing from
*/
void PrintLinkedList(const ListNode* head, std::ostream& stream = cout);



// -- Binary Tree
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

/*
    Container to store dynamically allocated tree nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline std::vector<TreeNode*> allocatedTreeNodes;

/*
    @brief Constructs a binary tree out of the given std::vector
    @param nodes The representation of nodes
    @return Root of tree

    Leetcode uses BFS to serialize binary trees into a std::string.
    ex:   1
         / \
        2   3
           / \
          4   5
    
    gets serialized into "[1,2,3,null,null,4,5]"

    * Check comment in source code for clearer visual representation
*/
TreeNode* CreateBinaryTree(const std::vector<std::string>& nodes);

/* 
    @brief Prints a preorder traversal of the given tree
    @param root Node to start from
*/
void PrintBinaryTree_Preorder(const TreeNode* root, std::ostream& stream = cout);



// -- Graph
struct GraphNode {
    int val;
    std::vector<GraphNode*> neighbors;

    GraphNode() : val(0), neighbors(std::vector<GraphNode*>()) {}
    GraphNode(int _val) : val(_val), neighbors(std::vector<GraphNode*>()) {}
    GraphNode(int _val, std::vector<GraphNode*> _neighbours) : val(_val), neighbors(_neighbours) {}
};

/*
    Container to store dynamically allocated graph nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline std::vector<GraphNode*> allocatedGraphNodes;

/*
    @brief Creates a graph from the given edge list
    @param edges Adjacency list
    @return Root of graph

    Each std::vector<int> in edges is an edge between two nodes.
*/
GraphNode* CreateGraph(const std::vector<std::vector<int>>& edges);

/*
    @brief Driver for performing a DFS on the given graph
    @param root Node to start the DFS from
*/
void PrintGraph_DFS(const GraphNode* root, std::ostream& stream = cout);

/*
    @brief Actually performs the DFS
    @param node Node currently being visited
    @param visited Adjacency list
*/
void PrintGraph_DFS(const GraphNode* node, std::set<const GraphNode*>& visited, std::ostream& = cout);



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


// -- Performance Counters
typedef std::chrono::_V2::system_clock::time_point TimePoint;

// Used to determine what format to print, in TimeElapsed()
enum TimePrecision {
    MICROSECONDS = 1,
    MILLISECONDS = 2,
    SECONDS = 3
};

/* 
    @brief Gives the current system time in microseconds
    @return Current system time in microseconds
*/
TimePoint TimeNow();

/* 
    @brief Calculates the time difference between `start` and current time
    @param `start` Start of the interval
    @param `precision` Whether to print microseconds, milliseconds, or seconds elapsed since start (default: MILLISECONDS)
    @param `division` What to divide the result of end-start by, useful for calculating average time in loops (default: 1)
    @return String of format "`Time elapsed: {time} {unit}`\n"

    NOTE: If you want to pass a division parameter, you also need to pass a TimePrecision parameter, you cant skip it
*/
std::string TimeElapsed(TimePoint start, TimePrecision precision = TimePrecision::MILLISECONDS, int division = 1);

/* 
    @brief Calculates the time difference between `start` and current time
    @param `start` Start of the interval
    @param `end` End of the interval
    @param `precision` Whether to print microseconds, milliseconds, or seconds elapsed since start (default: MILLISECONDS)
    @param `division` What to divide the result of end-start by, useful for calculating average time in loops (default: 1)
    @return String of format "`Time elapsed: {time} {unit}`\n"

    NOTE: If you want  to pass a division parameter, you also need to pass a TimePrecision parameter, you cant skip it
*/
std::string TimeElapsed(TimePoint start, TimePoint end, TimePrecision precision = TimePrecision::MILLISECONDS, int division = 1);


#endif