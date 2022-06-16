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
    bool isValidBST(TreeNode* root) {
        // left subtree is valid, right subtree is valid + (leftMax < root < rightMin)
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
            return true;

        return isValidBST(root->left) && 
               isValidBST(root->right) &&
               (getMax(root->left) < root->val && getMin(root->right) > root->val);
            
    }

    double getMin(TreeNode *node) {
        if (node == nullptr) return INFINITY;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    double getMax(TreeNode *node) {
        if (node == nullptr) return -INFINITY;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }
};