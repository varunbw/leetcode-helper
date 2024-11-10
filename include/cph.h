#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <bits/stdc++.h>
using namespace std;



// -- Input Parsing
/*
    @brief Parse inputs as ints from the command line, and put them in a vector<int>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in vector<int> format

    This works on space separated numbers as well as
    a single argument as follows [1,2,3,4]
*/
vector<int> ArgsParseInt_1D(const int, char**, const int);

/*
    @brief Parse inputs as ints from the command line, and put them in a vector<vector<int>>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in vector<vector<int>> format

    This works with the following format only:
        [[1,2,3],[4,5,6],[7,8,9]].

    The above argument is a single string
*/
vector<vector<int>> ArgsParseInt_2D(const int, char**, const int);

/*
    @brief Parse inputs as ints from the command line, and put them in a vector<string>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in vector<string> format

    Works on space separated values as well as a single value like this ["hello world","checking","1234"]
*/
vector<string> ArgsParseString_1D(const int, char**, const int);



// -- Vector Printing
template <typename T>
void Print1DVector(vector<T> vec) {
    for (auto ele : vec)
        cout << ele << "  ";
    cout << "\n";

    return;
}

template <typename T>
void Print2DVector(vector<vector<T>> vec) {
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
inline vector<ListNode*> allocatedListNodes;

/*
    @brief Does what it says
    @param vec Vector to convert to a linked list
    @return Head of linked list
*/
ListNode* CreateLinkedList(const vector<int>&);

/*
    @brief Does what it says, prints to std::cout
    @param head Node to start printing from
*/
void DisplayLinkedList(const ListNode*);



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
inline vector<TreeNode*> allocatedTreeNodes;

/*
    @brief Constructs a binary tree out of the given vector
    @param nodes The representation of nodes
    @return Root of tree

    Leetcode uses BFS to serialize binary trees into a string.
    ex:   1
         / \
        2   3
           / \
          4   5
    
    gets serialized into "[1,2,3,null,null,4,5]"

    * Check comment in source code for clearer visual representation
*/
TreeNode* CreateBinaryTree(const vector<string>&);

/* 
    @brief Prints a preorder traversal of the given tree
    @param root Node to start from
*/
void BT_PreorderTraversal(const TreeNode*);



// -- Graph
struct GraphNode {
    int val;
    vector<GraphNode*> neighbors;

    GraphNode() : val(0), neighbors(vector<GraphNode*>()) {}
    GraphNode(int _val) : val(_val), neighbors(vector<GraphNode*>()) {}
    GraphNode(int _val, vector<GraphNode*> _neighbours) : val(_val), neighbors(_neighbours) {}
};

/*
    Container to store dynamically allocated graph nodes in.
    When nodes are no longer needed, go through this list and free them all.
    Not really needed unless you use Address Sanitizer.
    AddrSan will spam memory leak warnings if you don't free dynamically allocated memory
*/
inline vector<GraphNode*> allocatedGraphNodes;

/*
    @brief Creates a graph from the given edge list
    @param edges Adjacency list
    @return Root of graph

    Each vector<int> in edges is an edge between two nodes.

    TODO: Change to vector<pair<int, int>>
*/
GraphNode* CreateGraph(const vector<vector<int>>&);

/*
    @brief Driver for performing a DFS on the given graph
    @param root Node to start the DFS from
*/
void G_DFS(const GraphNode*);

/*
    @brief Actually performs the DFS
    @param node Node currently being visited
    @param visited Adjacency list
*/
void G_DFS(const GraphNode*, set<const GraphNode*>&);



// -- General
// -- Miscellaneous functions
/*
    @brief Frees up the memory of all tree and graph nodes
    Containers referred:
    - inline vector<ListNode*> allocatedListNodes;
    - inline vector<TreeNode*> allocatedTreeNodes;
    - inline vector<GraphNode*> allocatedGraphNodes;
*/
void DeleteAllocatedNodes();


// -- Performance Counters
typedef std::chrono::_V2::system_clock::time_point TimePoint;

/* 
    @brief Gives the current system time in microseconds
    @return Current system time in microseconds
*/
TimePoint TimeNow_Microseconds();

/* 
    @brief Calculates the time difference between `start` and current time
    @param start Start of the interval
    @param division What to divide the result of end-start by, useful for calculating average time in loops
    @return String of format "Time elapsed: {time} us\n"
*/
string TimeElapsed_Microseconds(TimePoint, int = 1);

/* 
    @brief Calculates the time difference between `start` and `end`
    @param start Start of the interval
    @param end End of the interval
    @param division What to divide the result of end-start by, useful for calculating average time in loops
    @return String of format "Time elapsed: {time} us\n"
*/
string TimeElapsed_Microseconds(TimePoint, TimePoint, int = 1);


#endif