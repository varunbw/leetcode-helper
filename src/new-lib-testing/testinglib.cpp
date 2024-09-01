#include <bits/stdc++.h>
#include "../../include/mylib.h"

using namespace std;

// -- Input Parsing
/*
    Parse inputs as ints from the command line
    This works on space separated numbers as well as
    a single argument as follows [1,2,3,4]
    
    I/P: argc, argv,
         offset to start parsing from (0 starts from argv[1])
    O/P: Parsed input in vector<int> format
*/
vector<int> ArgsParseInt_1D(int argc, char** argv, int offset) {

    if (argc <= 1) {
        cerr << "No input parameters\n\n";
        exit(0);
    }
    if (offset + 1 >= argc) {
        cerr << "Offset greater than num of parameters\n";
        exit(0);
    }

    vector<int> vec;

    // Case 1: space separated values
    if (argv[1 + offset][0] != '[')
        for (int i = 1 + offset; i < argc; i++) 
            vec.push_back(stoi(argv[i]));


    // Case 2: [1,2,3]
    else if (argv[1 + offset][0] == '[') {

        string inp = argv[1 + offset];

        inp.erase(inp.begin());
        inp.pop_back();

        stringstream ss(inp);
        string item;

        while (getline(ss, item, ','))
            vec.push_back(stoi(item));
    }

    return vec;
}

/*
    Parse a 2D matrix from the command line
    This works with the following format only:
        [[1,2,3],[4,5,6],[7,8,9]]
        The above argument is a single string
    
    I/P: argc, argv
         offset to start parsing from (0 starts from argv[1])
    O/P: Parsed input in vector<vector<int>> format
*/
vector<vector<int>> ArgsParseInt_2D(int argc, char** argv, int offset) {

    if (argc <= 1) {
        cerr << "No input parameters\n\n";
        exit(0);
    }
    if (offset + 1 >= argc) {
        cerr << "Offset greater than num of parameters\n";
        exit(0);
    }

    // Set input
    string inp = argv[1 + offset];

    if (inp[0] != '[' || inp[1] != '[') {
        cerr << "Invalid format for 2D parsing\n";
        exit(0);
    }

    // Final vector
    vector<vector<int>> vec;

    // Remove '[' and ']'
    inp.erase(inp.begin());
    inp.pop_back();

    stringstream ssOuter(inp);
    string itemOuter;
    
    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<int> row;

        stringstream ssInner(itemOuter);
        string itemInner;

        while(getline(ssInner, itemInner, ',')) {
            if (itemInner[0] == '[')
                itemInner.erase(itemInner.begin());

            row.push_back(stoi(itemInner));  
        }
        
        vec.push_back(row);
    }

    return vec;
}

/*
    Parse inputs as strings from the command line
    Works on space separated values as well as
    a single value like this [5,1,4,null,null,3,6]
    
    I/P: argc, argv
         offset to start parsing from (0 starts from argv[1])
    O/P: Parsed input in vector<string> format
*/
vector<string> ArgsParseString_1D(int argc, char** argv, int offset) {

    if (argc <= 1) {    
        cerr << "No input parameters\n\n";
        exit(0);
    }
    if (offset + 1 >= argc) {
        cerr << "Offset greater than num of parameters\n";
        exit(0);
    }

    vector<string> vec;

    // Case 1: space separated values
    if (argv[1][0] != '[')
        for (int i = 1 + offset; i < argc; i++)
            vec.push_back(argv[i]);
    

    // Case 2: [values, like, this]
    if (argv[1][0] == '[') {

        string inp = argv[1 + offset];

        // Remove '[' and ']'
        inp.erase(inp.begin());
        inp.pop_back();

        stringstream ss(inp);
        string item;

        while(getline(ss, item, ','))
            vec.push_back(item);
    }

    return vec;
}



// -- Linked List
/*
    ToDo: Could be better, maybe with while(cin >> val)
    Does what it says
    O/P: Head of linked list
*/
ListNode* CreateLinkedList() {

    ListNode* head = new ListNode;
    ListNode* prevNode = head;

    cout << "Enter -1 to stop:\n";

    while (true) {

        ListNode* newNode = new ListNode;
        
        cout << "Val: ";
        cin >> newNode->val;

        // End if -1
        if (newNode->val == -1) {
            delete newNode;
            break;
        }

        newNode->next = nullptr;
        prevNode->next = newNode;
        
        prevNode = newNode;
    }

    return head;
}

/*
    Does what it says
    I/P: Head of linked list
*/
void DisplayLinkedList(ListNode* head) {

    if (head->next == NULL) {
        cout << "List is empty, nothing to display\n";
        return;
    }

    ListNode* curr = head->next;
    while (curr) {
        cout << curr->val << ", ";
        curr = curr->next;
    }

    return;
}



// -- Binary Tree
/*
    Create a binary tree with the given vector
    Follows the format
        Left child pos  = (2 * node pos) + 1
        Right child pos = (2 * node pos) + 2
    
    ex: [1, 2, 3, null, null, 4, 5]
          1
         / \
        2   3
           / \
          4   5
    
    I/P: Vector of strings containing node values
         "null" or "n" signifies no node at corresponding location
    O/P: Pointer to root node
*/
TreeNode* CreateBinaryTree(vector<string>& inp) {

    vector<TreeNode*> nodes;
    
    const int inpSize = inp.size();
    if (inpSize == 0) {
        cerr << "Cannot make tree, vector empty";
        exit(0);
    }

    // Push "null" values and normal values accordingly
    for (int i = 0; i < inpSize; i++) {
        if (inp[i] == "null" || inp[i] == "n") {
            nodes.push_back(nullptr);
            continue;
        }

        nodes.push_back(new TreeNode(stoi(inp[i])));
    }

    // Link children
    for (int i = 0; i < inpSize/2; i++) {

        if (nodes[i] == nullptr) continue;

        int left  = (2 * i) + 1;
        int right = (2 * i) + 2;

        if (left  < inpSize) nodes[i]->left  = nodes[left];
        if (right < inpSize) nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

/*
    Prints a preorder traversal of the binary tree
    I/P: root node
*/
void BT_PreorderTraversal(TreeNode* root) {
    
    if (root == nullptr) return;
    
    cout << root->val << ", ";
    BT_PreorderTraversal(root->left);
    BT_PreorderTraversal(root->right);

    return;
}


// -- Graph
/*
    Creates a graph with the given edges
    Each vector<int> in edges is an edge between two nodes

    I/P: The edge list :)
    O/P: Root node of graph
*/
GraphNode* CreateGraph(vector<vector<int>>& edges) {

    if (edges.size() == 0) {
        cerr << "Cannot make graph from empty list\n";
        exit(0);
    }

    set<int> values;
    map<int, GraphNode*> nodes;

    // Init the unique set of all variables
    for (vector<int> link : edges) {
        values.insert(link[0]);
        values.insert(link[1]);
    }

    // Create nodes for each variable
    for (int val : values) {
        GraphNode* node = new GraphNode(val);
        nodes.insert({val, node});

        allocedGraphNodes.push_back(node);
    }

    // Make the neighbors list
    for (vector<int> link : edges) {
        nodes[link[0]]->neighbors.push_back(nodes[link[1]]);
    }

    return nodes[edges[0][0]];
}


/*
    Driver for performing a DFS on the given graph
    I/P: Root node
*/
void G_DFS(GraphNode* root) {
    set<GraphNode*> visited;
    G_DFS(root, visited);
}

void G_DFS(GraphNode* node, set<GraphNode*>& visited) {

    if (node == nullptr || visited.count(node) == 1)
        return;

    // Mark the node as visited
    visited.insert(node);

    // Process the current node (e.g., print its value)
    cout << node->val << " ";

    // Recursively visit all the neighbors
    for (GraphNode* neighbour : node->neighbors) 
        G_DFS(neighbour, visited);
    
}


// -- General Stuff
/*
    Frees up the memory of all tree and graph nodes
    I/P: Nodes vector
*/
void DeleteAllocatedNodes() {

    for (TreeNode* node : allocedTreeNodes)
        delete node;

    for (GraphNode* node : allocedGraphNodes)
        delete node;

    return;
}