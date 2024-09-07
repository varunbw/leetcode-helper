#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;


// -- Linked List
/*
    Does what it says
    O/P: Head of linked list
*/
ListNode* CreateLinkedList() {
    
    ListNode* head = new ListNode;
    allocatedListNodes.push_back(head);
    ListNode* prevNode = head;

    cout << "Enter -1 to stop:\n";

    int val = 0;
    while (cin >> val) {
        if (val == -1) break;
        ListNode* newNode = new ListNode(val, nullptr);
        allocatedListNodes.push_back(newNode);  

        prevNode->next = newNode;
        prevNode = newNode;
    }

    return head;
}

/*
    Does what it says
    I/P: Head of linked list
*/
void DisplayLinkedList(const ListNode* head) {

    if (head->next == NULL) {
        cerr << "List is empty, nothing to display\n";
        return;
    }

    ListNode* curr = head->next;
    while (curr) {
        cout << curr->val << ", ";
        curr = curr->next;
    }
    
    cout << endl;
    return;
}