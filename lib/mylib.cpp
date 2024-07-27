#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;

// -- Input Parsing
/*
    Parse inputs as ints from the command line
    This only works on space separated numbers as follows
        5, 1, 4, 3, 6, -2
    
    I/P: argc, argv,
         offset to start parsing from (0 starts from argv[1])
    O/P: Parsed input in vector<int> format
*/
vector<int> argsParseInt(int argc, char **argv, int offset) {

    if (argc <= 1) {
        cerr << "No input parameters\n\n";
        exit(0);
    }

    if (offset >= argc) {
        cerr << "Offset greater than num of parameters\n";
        exit(0);
    }

    vector<int> vec(argc - 1 - offset, 0);
    
    for (int i = 1 + offset; i < argc; i++) 
        vec[i - 1 - offset] = stoi(argv[i]);

    return vec;
}


/*
    Parse inputs as strings from the command line
    This only works on the following input format
        [5,1,4,null,null,3,6]
        The above thing is a SINGLE ARGUMENT
        ex: ./a.out [5,1,4,null,null,3,6]
    
    I/P: argc, argv
         offset to start parsing from (0 starts from argv[1])
    O/P: Parsed input in vector<string> format
    
*/
vector<string> argsParseString(int argc, char** argv, int offset) {

    if (argc <= 1) {    
        cerr << "No input parameters\n\n";
        exit(0);
    }
    if (offset >= argc) {
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

        string inp = argv[1];

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
    Does what it says
    O/P: Head of linked list
*/
ListNode* createLinkedList() {

    ListNode* head = new ListNode;
    ListNode* temp = head;

    cout << "Enter -1 to stop:\n";

    for (;;) {

        ListNode* curr = new ListNode;
        
        cout << "Val: ";
        cin >> curr->val;

        // End if -1
        if (curr->val == -1) {
            delete curr;
            break;
        }

        curr->next = nullptr;
        temp->next = curr;
        
        temp = curr;
    }

    return head;
}

/*
    Does what it says
    I/P: Head of linked list
*/
void displayLinkedList(ListNode* head) {

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
        
    I/P: Vector of strings containing node values
    O/P: Address of root node
*/
TreeNode* createBinaryTree(vector<string> inp, vector<TreeNode*>& nodes) {
    
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

        int left  = (2 * i) + 1;
        int right = (2 * i) + 2;

        if (left  < inpSize) nodes[i]->left  = nodes[left];
        if (right < inpSize) nodes[i]->right = nodes[right];
    }

    return nodes[0];
}

/*
    Frees up the memory of all nodes in the vector
    I/P: Nodes vector
*/
void deleteNodes(vector<TreeNode*>& nodes) {

    for (TreeNode* node : nodes)
        delete node;

    return;
}











// * End of Binary Tree operations