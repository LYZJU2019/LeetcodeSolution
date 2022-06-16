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
    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }

    // 以left为根节点的子树是否与以right为根的子树轴对称
    bool helper(TreeNode *left, TreeNode *right) {
        if (left == nullptr) return right == nullptr;

        return (right != nullptr) &&
               (left->val == right->val) &&
               helper(left->left, right->right) &&
               helper(left->right, right->left);
    }
};