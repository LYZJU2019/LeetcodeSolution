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
    // *************************************************************
    // ***********************向上标记法*****************************
    // *************************************************************
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        helper(root);
        unordered_set<TreeNode *> set;

        set.insert(p);
        while (p != root) {
            set.insert(map[p->val]);
            p = map[p->val];
        }
        set.insert(root);

        while (q != root) {
            if (set.find(q) != set.end()) return q;
            q = map[q->val];
        }
        
        return root;
    }

    // 维护一个int -> int的映射，储存每个节点的父节点（遍历实现）
    // root不为空
    void helper(TreeNode *root) {
        if (root->left != nullptr) {
            map[(int)root->left->val] = root;
            helper(root->left);
        }
        if (root->right != nullptr) {
            map[(int)root->right->val] = root;
            helper(root->right);
        }
    }

    // ****************************************************************
    // *****************************递归实现****************************
    // ****************************************************************
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        helper(root);
        return ans;
    }

    // 考虑每个节点是否是p和q的公共祖先，返回最深的祖先
    // 返回一个pair，其中第一个元素表示以root为根节点的树是否包含p
    // 第二个元素表示以root为根节点的树是否包含q
    pair<int, int> helper(TreeNode *root) {
        if (root == nullptr) return {false, false};
        auto lres = helper(root->left);
        auto rres = helper(root->right);
        pair<bool, bool> res;
        res.first = lres.first || rres.first || root->val == p->val;
        res.second = lres.second || rres.second || root->val == q->val;
        if (res.first && res.second && ans == nullptr) ans = root;
        return res;
    }

private:
    TreeNode *p;
    TreeNode *q;
    TreeNode *ans;
    unordered_map<int, TreeNode *> map;
};