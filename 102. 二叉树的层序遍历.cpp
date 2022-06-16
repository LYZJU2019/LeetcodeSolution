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
    // **********************************************************************
    // ******************************基于递归实现*****************************
    // **********************************************************************
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        auto left = levelOrder(root->left);
        auto right = levelOrder(root->right);

        ans.push_back({root->val});
        vector<int> left_arr, right_arr;
        for (int i = 0; i < max(left.size(), right.size()); i++) {
            if (i >= left.size()) left_arr = {};
            else left_arr = left[i];
            if (i >= right.size()) right_arr = {};
            else right_arr = right[i];
            left_arr.insert(left_arr.end(), right_arr.begin(), right_arr.end());
            ans.push_back(left_arr);
        }

        return ans;
    }
};