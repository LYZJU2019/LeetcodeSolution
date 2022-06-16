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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small_head = nullptr, *geql_head = nullptr;
        ListNode *small_tail = nullptr, *geql_tail = nullptr;
        while (head != nullptr) {
            ListNode *nextHead = head->next;
            if (head->val >= x) {
                if (geql_head == nullptr) {
                    geql_head = head;
                    geql_tail = head;
                }
                else {
                    geql_tail->next = head;
                    geql_tail = head;
                }
                geql_tail->next = nullptr;
            } else {
                if (small_head == nullptr) {
                    small_head = head;
                    small_tail = head;
                }
                else {
                    small_tail->next = head;
                    small_tail = head;
                }
                small_tail->next = nullptr;
            }
            head = nextHead;
        }
        if (small_tail != nullptr) {
            small_tail->next = geql_head;
            return small_head;
        }

        return geql_head;
    }
};