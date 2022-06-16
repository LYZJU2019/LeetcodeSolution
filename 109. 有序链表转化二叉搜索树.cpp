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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 先建立一个数组，存放node的地址
    TreeNode* sortedListToBST(ListNode* head) {
        while (head != nullptr) {
            nodes.push_back(head);
            head = head->next;
        }
        return build(0, nodes.size());
    }

    // 由nums[begin,...,end-1]构建二叉搜索树，返回根节点
    TreeNode *build(int begin, int end) {
        if (begin == end) return nullptr;
        if (begin == end - 1) return new TreeNode(nodes[begin]->val);

        int mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(nodes[mid]->val);
        root->left = build(begin, mid);
        root->right = build(mid + 1, end);
        return root;
    }

private:
    vector<ListNode *> nodes;
};