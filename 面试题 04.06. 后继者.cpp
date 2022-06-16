/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 如果p有右子树，那么后继一定是右子树的最小值
    // 否则，调用查找算法，后继一定是查找路径中的某一个节点
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == nullptr) return nullptr;
        TreeNode *cur = nullptr;

        if (p->right != nullptr) {
            cur = p->right;
            while (cur->left != nullptr) {
                cur = cur->left;
            }
            return cur;
        }
        int minval = (root->val > p->val ? root->val : INT_MAX);
        TreeNode *succ = (root->val > p->val ? root : nullptr);
        cur = root;
        while (cur != nullptr && cur != p) {
            if (cur->val > p->val && minval > cur->val) {
                minval = cur->val;
                succ = cur;
            }
            cur = (cur->val > p->val ? cur->left : cur->right);
        }
        if (cur == nullptr) return nullptr;

        return succ;
    }
};