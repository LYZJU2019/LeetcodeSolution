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
    // preorder的第一个元素是根，从inorder里面找到和preorder中第一个元素相等的元素的位置并以此为界
    // 左边的是左子树，右边的是右子树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1);
    }

    // [2, 4, 5, 7, 8]
    // [3, 1, 2]
    // 从preorder和inorder的部分序列中构造子树，返回根节点
    TreeNode *helper(vector<int> &preorder, int begin_pre, int end_pre, 
                vector<int> &inorder, int begin_in, int end_in) {
        if (begin_pre > end_pre) return nullptr;
        TreeNode *root = new TreeNode(preorder[begin_pre]);

        int i;
        for (i = begin_in; i <= end_in && inorder[i] != preorder[begin_pre]; i++)
            ;
        root->left = helper(preorder, begin_pre + 1, begin_pre + (i - begin_in), 
                            inorder, begin_in, i - 1);

        root->right = helper(preorder, begin_pre + (i - begin_in) + 1, end_pre,
                             inorder, i + 1, end_in);
        
        return root;
    } 
};