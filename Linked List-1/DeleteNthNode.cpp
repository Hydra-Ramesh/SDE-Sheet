#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        int length = 0;
        for (ListNode* temp = head; temp != NULL; temp = temp->next) {
            length++;
        }
        if (length == n) return head->next;
        for (int i = 1; i < length - n; i++) {
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

// Function to print the list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to add a node at the end of the list
void appendNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    ListNode* head = NULL;

    // Creating a linked list: 1->2->3->4->5
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    cout << "Original List: ";
    printList(head);

    Solution solution;
    int n = 2;

    // Remove the 2nd node from the end (which is node 4)
    head = solution.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from the end: ";
    printList(head);

    return 0;
}
