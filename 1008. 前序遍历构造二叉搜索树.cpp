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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->preorder = preorder;
        return build(0, preorder.size() - 1);
    }

    // 从[begin, end]构造二叉搜索树
    TreeNode *build(int begin, int end) {
        if (begin > end) return nullptr;

        TreeNode *root = new TreeNode(preorder[begin]);
        int i;
        for (i = begin; i <= end && preorder[i] <= preorder[begin]; i++)
            ;
        root->left = build(begin + 1, i-1);
        root->right = build(i, end);
        return root;
    }

private:
    vector<int> preorder;
};