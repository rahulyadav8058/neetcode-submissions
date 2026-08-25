/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* ptr = head;
        ListNode* ptr2 = head;

        for (int i = 0; i < n; i++) {
            ptr = ptr->next;
        }

        if (ptr == nullptr) {
            return head->next;
        }

        while (ptr->next != nullptr) {
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }

        ptr2->next = ptr2->next->next;

        return head;
    }
};