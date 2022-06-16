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
    // **********************************************************
    // *************************递归实现**************************
    // **********************************************************
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr) return nullptr;
        if (root->val == val) return root; 
        if (root->val > val) return searchBST(root->left, val);
        return searchBST(root->right, val);
    }

    // **********************************************************
    // *************************迭代实现**************************
    // **********************************************************
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *cur = root;
        while (cur != nullptr) {
            if (cur->val == val) return cur;
            cur = (cur->val > val ? cur->left : cur->right);
        }

        return nullptr;
    }
};