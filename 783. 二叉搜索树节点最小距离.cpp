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
    // 中序遍历，记录前一个节点，不断更新min
    int minDiffInBST(TreeNode* root) {
        this->ans = INT_MAX;
        this->prev = nullptr;
        inorder(root);
        return ans;
    }

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            // 左子树遍历完成后，前一个节点已经保存在了prev里面
            if (prev != nullptr)
                ans = min(ans, root->val - prev->val);
            // 跟新prev
            prev = root;
            inorder(root->right);
        }
    }

private:
    int ans;
    TreeNode *prev;
};