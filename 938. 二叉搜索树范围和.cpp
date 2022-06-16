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
    int rangeSumBST(TreeNode* root, int low, int high) {
        this->ans = 0;
        this->low = low;
        this->high = high;
        inorder(root);
        return ans;
    }

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            if (root->val >= low && root->val <= high) {
                ans += root->val;
            }
            inorder(root->right);
        }
    }

private:
    int ans;
    int low;
    int high;
};