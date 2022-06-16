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
        ListNode *sp = head;
        ListNode *fp = head;
        ListNode *protect = new ListNode(0, head);
        ListNode *prev = protect;
        
        while (--n) {
            fp = fp->next;
        }
        while (fp->next != nullptr) {
            sp = sp->next;
            fp = fp->next;
            prev = prev->next;
        }
        prev->next = sp->next;
        return protect->next;
    }
};