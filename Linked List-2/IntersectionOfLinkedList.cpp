#include <iostream>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode *tempA = headA, *tempB = headB;

        // Calculate the length of list A
        while (tempA) {
            lenA++;
            tempA = tempA->next;
        }

        // Calculate the length of list B
        while (tempB) {
            lenB++;
            tempB = tempB->next;
        }

        // Reset pointers to head
        tempA = headA;
        tempB = headB;

        // Move the pointer of the longer list forward by the length difference
        int diff = abs(lenA - lenB);
        while (diff--) {
            if (lenA > lenB) tempA = tempA->next;
            else tempB = tempB->next;
        }

        // Traverse both lists together to find the intersection point
        while (tempA && tempB) {
            if (tempA == tempB) return tempA; // Found intersection
            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr; // No intersection
    }
};

// Function to create a linked list from a vector
ListNode* createLinkedList(vector<int> values) {
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

// **Main function to test intersection logic**
int main() {
    // Creating two separate linked lists
    ListNode* common = createLinkedList({8, 10, 12}); // Common part

    ListNode* headA = createLinkedList({1, 2, 3});
    ListNode* headB = createLinkedList({4, 5});

    // Attaching the common part
    ListNode* temp = headA;
    while (temp->next) temp = temp->next;
    temp->next = common; // Link A to common

    temp = headB;
    while (temp->next) temp = temp->next;
    temp->next = common; // Link B to common

    cout << "Linked List A: ";
    printLinkedList(headA);

    cout << "Linked List B: ";
    printLinkedList(headB);

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
