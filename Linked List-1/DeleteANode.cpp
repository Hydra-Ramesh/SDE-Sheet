#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function
int main() {
    // Create a linked list: 4 -> 5 -> 1 -> 9
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    // Print the original list
    cout << "Original list: ";
    printList(head);

    // Create a Solution object and delete the node with value 5
    Solution solution;
    solution.deleteNode(head->next);  // Delete the node with value 5

    // Print the modified list
    cout << "Modified list: ";
    printList(head);

    // Clean up the memory
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}
