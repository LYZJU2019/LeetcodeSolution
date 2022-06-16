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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            // 删除的节点没有子树，直接删除就好了
            if (root->left == nullptr && root->right == nullptr) return nullptr;
            // 如果只有一个子树，返回子树的根
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            // 如果有两课子树，找到根节点的后继代替根节点，删除后继
            TreeNode *succ = root->right;
            while (succ->left != nullptr) succ = succ->left;
            TreeNode *newroot = deleteNode(root, succ->val);
            newroot->val = succ->val;
            return newroot;
        }

        if (root->val > key) 
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        
        return root;
    }
};