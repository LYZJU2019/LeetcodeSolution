/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode *fp = head, *sp = head;
        do {
            if (sp->next == nullptr) return false;
            if (fp->next == nullptr || fp->next->next == nullptr) return false;
            fp = fp->next->next;
            sp = sp->next;
        } while (fp != sp);

        return true;
    }
};