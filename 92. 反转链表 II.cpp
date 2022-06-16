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
        ListNode *protect = new ListNode(0, head);
        ListNode *cur = protect;
        // find the start node
        while (--left) {
            cur = cur->next;
            right--;
        }

        ListNode *start = cur->next;
        ListNode *prev = cur;
        // find the node that points after right (maybe null)
        while (right--) {
            cur = cur->next;
        }
        // reverse node in [left, right)
        ListNode *end = cur->next;
        reverseHelper(start, end);
        start->next = end;
        prev->next = cur;
        return protect->next;
    }

    void reverseHelper(ListNode *head, ListNode *stop) {
        ListNode *last = head;
        head = head->next;
        while (head != stop) {
            ListNode *temp = head->next;
            head->next = last;
            last = head;
            head = temp;
        }
    }
};