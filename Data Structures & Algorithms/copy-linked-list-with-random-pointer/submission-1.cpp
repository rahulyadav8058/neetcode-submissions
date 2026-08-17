/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)return nullptr;
        Node* head2 = head;
        Node* head3 = head;
        while (head) {
            Node* temp = new Node(head->val);
            Node* next = head->next;
            head->next = temp;
            temp->next = next;
            head = head->next->next;
        }

        while (head2) {
            Node* random2 = head2->random;
            Node* dup = head2->next;
            if (random2 == nullptr) {
                dup->random = nullptr;
            } else {
                dup->random = random2->next;
            }
            head2 = head2->next->next;
        }

        Node* ans = head3->next;
        Node* an = ans;

        while (head3) {
            Node* node = head3->next;
            head3->next = head3->next->next;
            if (head3->next == nullptr) {
                node->next = nullptr;
            } else {
                node->next = node->next->next;
            }
            head3 = head3->next;
        }
        return ans;
    }
};
