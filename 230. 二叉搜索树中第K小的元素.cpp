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
    // 中序遍历到第K个元素时停止
    int kthSmallest(TreeNode* root, int k) {
        this->cur = 0;
        this->ans = -1;
        this->k = k;
        inorder(root);
        return ans;
    }

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            cur++;
            if (cur == k) ans = root->val;
            inorder(root->right);
        }
    }

private:
    int cur;
    int ans;
    int k;
};