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
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return newroot;
    }

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            if (newroot == nullptr) {
                newroot = new TreeNode(root->val);
                cur = newroot;
            } else {
                cur->right = new TreeNode(root->val);
                cur = cur->right;
            }
            inorder(root->right);
        }
    }

private:
    TreeNode *newroot;
    TreeNode *cur;
};