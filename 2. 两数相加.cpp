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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum;
        int val1, val2;
        ListNode *protect = new ListNode(0, nullptr);
        ListNode *last = protect;
        while (l1 != nullptr || l2 != nullptr || carry) {
            // construct list
            ListNode *newnode = new ListNode(0, nullptr);
            last->next = newnode;
            // compute
            val1 = (l1 == nullptr ? 0 : l1->val);
            val2 = (l2 == nullptr ? 0 : l2->val);
            sum = val1 + val2 + carry;
            newnode->val = sum % 10;
            carry = sum / 10;
            // update
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
            last = last->next;
        }
        return protect->next;
    }
};