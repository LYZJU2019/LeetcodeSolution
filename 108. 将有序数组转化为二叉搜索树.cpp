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
    // 中间的数为根
    // 左边为左子树，右边为右子树
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums = nums;
        return build(0, nums.size());
    }

    // 由nums[begin, ...,end-1]建立一个二叉搜索树
    TreeNode *build(int begin, int end) {
        if (begin == end) return nullptr;
        if (begin == end - 1) return new TreeNode(nums[begin]);
        int mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(begin, mid);
        root->right = build(mid + 1, end);
        return root;
    }

private:
    vector<int> nums;
};