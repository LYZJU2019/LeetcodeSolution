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
    // *****************************************************************
    // ***************************基于Hashset的实现**********************
    // *****************************************************************
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while (head != nullptr) {
            if (set.find(head) != set.end())
                return head;
            set.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};