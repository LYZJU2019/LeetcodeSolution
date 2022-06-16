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
    ListNode* swapPairs(ListNode* head) {
        ListNode *protect = new ListNode(0, head);
        ListNode *prev = protect;

        while (head != nullptr) {
            ListNode *end = head->next;
            if (end == nullptr) break;
            ListNode *nextHead = end->next;

            // reverse
            end->next = head;

            // update
            prev->next = end;
            head->next = nextHead;
            prev = head;
            head = nextHead;
        }

        return protect->next;
    }
};