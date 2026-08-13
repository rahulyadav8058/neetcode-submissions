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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        int pos =1;
        while ( pos != left) {
            prev = node;
            node = node->next;
            pos++;
        }

        if (prev) {
            prev->next = nullptr;
        }

        ListNode* righ = node;
        while (pos != right) {
            righ = righ->next;
            pos++;
        }

        ListNode* righ_next = nullptr;
        if (righ->next) {
            righ_next = righ->next;
        }

        ListNode* curr = node;
        ListNode* prev2 = nullptr;
        righ->next = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev2;

            prev2 = curr;

            curr = next;
        }

        if (prev) {
            prev->next = prev2;
        }
            node->next = righ_next;
        
        if (prev) return head;
        return prev2;
    }
};