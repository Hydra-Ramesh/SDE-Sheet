#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* tempA = a;
        ListNode* tempB = b;
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        while(tempA != NULL && tempB != NULL) {
            if(tempA->val <= tempB->val) {
                ListNode* t = new ListNode(tempA->val);
                tempC->next = t;
                tempC = t;
                tempA = tempA->next;
            } else {
                ListNode* t = new ListNode(tempB->val);
                tempC->next = t;
                tempC = t;
                tempB = tempB->next;
            }
        }
        if(tempA == NULL) {
            tempC->next = tempB;
        } else {
            tempC->next = tempA;
        }
        return c->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating two sample linked lists: 1 -> 3 -> 5 and 2 -> 4 -> 6
    ListNode* a = new ListNode(1);
    a->next = new ListNode(3);
    a->next->next = new ListNode(5);

    ListNode* b = new ListNode(2);
    b->next = new ListNode(4);
    b->next->next = new ListNode(6);

    cout << "List A: ";
    printList(a);
    cout << "List B: ";
    printList(b);

    // Merge the two linked lists
    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(a, b);

    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
