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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return build(0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *build(int ib, int ie, int pb, int pe) {
        if (ib > ie) return nullptr;
        // 后序遍历序列最后一项为根节点
        TreeNode *root = new TreeNode(postorder[pe]);
        // cout << root->val << endl;
        // 从中序遍历的序列中找到根节点
        //    left  i  right
        //i [xxxxxx | xxxxx]
        //p [xxxxxx,xxxxx|]
        int i;
        for (i = ib; i <= ie && inorder[i] != postorder[pe]; i++)
            ;
        // cout << i << endl;
        root->left = build(ib, i-1, pb, pb + (i - ib) - 1); 
        root->right = build(i+1, ie, pb + (i - ib), pe - 1);
        return root;

    }

private:
    vector<int> inorder;
    vector<int> postorder;
};