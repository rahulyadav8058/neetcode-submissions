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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* head2 =head;
        ListNode* prevTail =nullptr;
        while(true){
            for(int i=0;i<k;i++){
                if(head2 == nullptr){return head;}
                head2 = head2->next;
                
            }
            ListNode* curr = temp;
            ListNode* prev = nullptr;
            //ListNode* next_point = temp->next;
            for(int i=0;i<k;i++){
                ListNode* next = curr->next;
                curr->next = prev;
                prev= curr;
                curr = next;
            }
            if(head == temp){
                head = prev;
            }
            if (prevTail)
                prevTail->next = prev;

            temp ->next = curr;
            prevTail = temp;
            temp = curr;

        }
    }
};
