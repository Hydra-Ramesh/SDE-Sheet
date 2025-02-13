#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
        ListNode* currNode = head;
        stack<int> s;

        // Push all elements onto the stack
        while (currNode != nullptr) {
            s.push(currNode->val);
            currNode = currNode->next;
        }

        // Compare stack elements with linked list values
        while (head != nullptr) {
            int c = s.top();
            s.pop();
            if (head->val != c) {
                return false; // Not a palindrome
            }
            head = head->next;
        }
        return true;
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

// **Main function to test palindrome detection**
int main() {
    // Test Case 1: Palindrome linked list (1 -> 2 -> 3 -> 2 -> 1)
    vector<int> values1 = {1, 2, 3, 2, 1};
    ListNode* head1 = createLinkedList(values1);
    
    Solution sol;
    cout << "Is palindrome? " << (sol.isPalindrome(head1) ? "Yes" : "No") << endl;

    // Test Case 2: Non-palindrome linked list (1 -> 2 -> 3 -> 4 -> 5)
    vector<int> values2 = {1, 2, 3, 4, 5};
    ListNode* head2 = createLinkedList(values2);
    
    cout << "Is palindrome? " << (sol.isPalindrome(head2) ? "Yes" : "No") << endl;

    return 0;
}

