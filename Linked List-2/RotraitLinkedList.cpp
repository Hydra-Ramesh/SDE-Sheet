#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;

        int n = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;

        // Count the length of the list and get the tail node
        while (temp != NULL) {
            if (temp->next == NULL) tail = temp;
            temp = temp->next;
            n++;
        }

        // Reduce k to within range
        k = k % n;
        if (k == 0) return head;

        // Find the new head (n-k)th node
        temp = head;
        for (int i = 1; i < n - k; i++) {
            temp = temp->next;
        }

        // Adjust pointers to rotate the list
        tail->next = head;  // Connect tail to head
        head = temp->next;  // New head
        temp->next = NULL;  // Break the link

        return head;
    }
};

// Function to create a linked list from a vector
ListNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// **Main function to test rotateRight**
int main() {
    vector<int> values = {1, 2, 3, 4, 5};  // Example linked list
    int k = 2;  // Number of rotations

    ListNode* head = createLinkedList(values);
    
    cout << "Original List: ";
    printLinkedList(head);

    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List: ";
    printLinkedList(head);

    return 0;
}

