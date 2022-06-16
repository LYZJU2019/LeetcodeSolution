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
    // *************************************************************
    // ******************************基于递归实现********************
    // *************************************************************
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *newhead = reverseList(head->next);
        ListNode *cur;
        head->next->next = head;
        head->next = nullptr;   // otherwise form a cycle
        return newhead;
    }

    // ************************************************************** 
    // *****************************基于遍历实现**********************
    // **************************************************************
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *prev = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
};