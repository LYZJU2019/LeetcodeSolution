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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *protect = new ListNode(0, nullptr);
        ListNode *prev = protect;  // last node in the result linked list

        ListNode *last = head;  // last element seen in the linked list
        ListNode *cur = head->next; // current accessing node
        bool replicate = false;
        while (1) {
            if (cur == nullptr || cur->val != last->val) {
                if (!replicate) {
                    prev->next = last;
                    prev = prev->next;
                    prev->next = nullptr;  // safety
                } else {
                    replicate = false;
                }
            } else {
                replicate = true;
            }
            last = cur;
            if (cur == nullptr) break;
            cur = cur->next; 
        }
        return protect->next;
    }
};