#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* DummyNode = new ListNode(-1);
        ListNode* curr = DummyNode;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while(temp1 != NULL || temp2 != NULL){
            int sum = carry;
            if(temp1){
                sum += temp1->val;
            }
            if(temp2){
                sum += temp2->val;
            }
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newNode;
            curr = curr->next;
            if(temp1){
                temp1 = temp1->next;
            }
            if(temp2){
                temp2 = temp2->next;
            }
        }
        if(carry) {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        return DummyNode->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* createList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; ++i) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3};  // represents the number 342
    int arr2[] = {5, 6, 4};  // represents the number 465

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);  // Output should be 7 -> 0 -> 8 (representing 807)

    return 0;
}
