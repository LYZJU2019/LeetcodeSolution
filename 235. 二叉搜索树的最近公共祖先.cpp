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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        find(root);
        return ans;
    }

    // root: 7  p: 8 q : 9
    pair<int, int> find(TreeNode *root) {
        if (root == nullptr) return {false, false};

        auto lres = find(root->left);
        auto rres = find(root->right);
        pair<int, int> res;
        res.first = (lres.first || rres.first || root->val == p->val);
        res.second = (lres.second || rres.second || root->val == q->val);
        if (res.first && res.second && ans == nullptr) ans = root;
        return res;
    }

private:
    TreeNode *p;
    TreeNode *q;
    TreeNode *ans;
};