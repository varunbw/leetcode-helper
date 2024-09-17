#include <bits/stdc++.h>
#include "../include/mylib.h"

using namespace std;


// -- Linked List
/*
    @brief Does what it says
    @return Head of linked list
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
    @brief Does what it says, prints to std::cout
    @param head Node to start printing from
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