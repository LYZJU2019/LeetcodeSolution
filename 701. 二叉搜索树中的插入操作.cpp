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
    // *********************************************************
    // **************************递归插入************************
    // *********************************************************
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }

        if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        
        return root;
    }

    // *************************************************************
    // ******************************迭代***************************
    // *************************************************************
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *parent = nullptr;
        TreeNode *cur = root;

        while (cur != nullptr) {
            parent = cur;
            cur = (cur->val > val ? cur->left : cur->right);
        }

        TreeNode *newnode = new TreeNode(val);
        if (parent == nullptr) return newnode;
        if (parent->val > val)
            parent->left = newnode;
        else
            parent->right = newnode;
        return root;
    }
};