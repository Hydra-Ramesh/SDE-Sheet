#include <iostream>
#include <unordered_set>
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // Move slow pointer by 1 step
            fast = fast->next->next;    // Move fast pointer by 2 steps
            
            if (slow == fast) return true; // Cycle detected
        }
        return false; // No cycle
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

// Function to print a linked list (for debugging purposes)
void printLinkedList(ListNode* head) {
    unordered_set<ListNode*> visited;
    while (head) {
        if (visited.count(head)) { // If cycle is detected
            cout << "(Cycle detected at " << head->val << ")";
            break;
        }
        visited.insert(head);
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// **Main function to test cycle detection**
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL (No cycle)
    ListNode* head = createLinkedList({1, 2, 3, 4, 5});

    // Creating a cycle manually: 5 -> 3 (Back to node with value 3)
    ListNode* temp = head;
    ListNode* cycleNode = nullptr;
    while (temp->next) {
        if (temp->val == 3) cycleNode = temp; // Save node with value 3
        temp = temp->next;
    }
    temp->next = cycleNode; // Creating cycle

    Solution sol;
    bool result = sol.hasCycle(head);

    if (result)
        cout << "Cycle detected in the linked list!\n";
    else
        cout << "No cycle detected in the linked list.\n";

    return 0;
}

