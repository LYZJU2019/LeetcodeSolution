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
        // much like removing duplicates in array
        if (head == nullptr) return head;

        ListNode *fp = head->next, *sp = head;
        while (fp != nullptr) {
            if (fp->val != sp->val) {
                sp->next = fp;
                sp = sp->next;
            }
            fp = fp->next;
        }

        sp->next = nullptr;
        return head;
    }
};