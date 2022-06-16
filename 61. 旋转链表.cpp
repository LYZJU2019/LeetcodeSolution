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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;
        
        int length = getLength(head);
        int valid_rot = k % length;
        if (valid_rot == 0) return head;

        // two pointers (sp and fp)
        ListNode *fp = head, *sp = head;
        while (valid_rot--) {
            fp = fp->next;
        }
        while (fp->next != nullptr) {
            fp = fp->next;
            sp = sp->next;
        }
        fp->next = head;
        ListNode *newhead = sp->next;
        sp->next = nullptr;
        return newhead;
    }

    int getLength(ListNode *head) {
        if (head == nullptr) return 0;
        int length = 0;
        while (head != nullptr) {
            head = head->next;
            length++;
        }
        return length;
    }
};