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
    bool findTarget(TreeNode* root, int k) {
        this->k = k;
        this->ans = false;
        inorder(root);
        return ans;
    }

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            if (set.find(k - root->val) != set.end()) {
                ans = true;
                return;
            } 
            set.insert(root->val);
            inorder(root->right);
        }
    }

private:
    unordered_set<int> set;  // 存放之前看到过的数字
    int k;
    bool ans;
};