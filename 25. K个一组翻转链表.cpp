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
        // group the input list, each group has k elements (start, end)
        // reverse (inner)
        // modify the pointer before and after this group
        ListNode *protect = new ListNode(0, head);
        ListNode *last = protect;

        while (head != nullptr) {
            ListNode *end = getEnd(head, k);

            if (end == nullptr) break;

            ListNode *nextGroupHead = end->next;
            ReverseInner(head, nextGroupHead);

            last->next = end;
            head->next = nextGroupHead;
            last = head;
            head = nextGroupHead;
        }

        return protect->next;
    }

    ListNode *getEnd(ListNode *head, int k) {
        while (head != nullptr) {
            k--;
            if (k == 0) return head;
            head = head->next;
        }

        return nullptr;
    } 

    void ReverseInner(ListNode *head, ListNode *stop) {
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