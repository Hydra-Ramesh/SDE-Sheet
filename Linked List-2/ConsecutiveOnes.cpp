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
    int findMaxConsecutiveOnes(ListNode* head) {
        int maxCount = 0, count = 0;
        while (head) {
            if (head->val == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
            head = head->next;
        }
        return maxCount;
    }
};

// Function to create a linked list from an array
ListNode* createLinkedList(const int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// **Main function to test findMaxConsecutiveOnes**
int main() {
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1};  // Example linked list
    int n = sizeof(arr) / sizeof(arr[0]);
    
    ListNode* head = createLinkedList(arr, n);
    
    Solution sol;
    int result = sol.findMaxConsecutiveOnes(head);

    cout << "Max Consecutive Ones: " << result << endl;  // Expected Output: 3

    return 0;
}

