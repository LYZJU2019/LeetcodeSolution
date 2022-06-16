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
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        for (auto KV_pair : count) {
            ans[KV_pair.second].push_back(KV_pair.first);
        }
        return (--ans.end())->second;
    }

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            count[root->val]++;
            inorder(root->right);
        }   
    }

private:
    unordered_map<int, int> count;
    map<int, vector<int>> ans;
};