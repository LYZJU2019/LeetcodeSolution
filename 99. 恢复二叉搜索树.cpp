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
    // [1,8,5,7,3]
    void recoverTree(TreeNode* root) {
        traverse(root);
        
        int first = -1, second = -1;
        for (int prev = 0, cur = 1; cur < val.size(); cur++, prev++) {
            if (val[prev] > val[cur]) {
                if (first == -1) first = prev;
                else second = cur;
            }
        } 

        if (second == -1) second = first + 1;
        swap(node[first]->val, node[second]->val);
    }

    void traverse(TreeNode *root) {
        if (root != nullptr) {
            traverse(root->left);
            val.push_back(root->val);
            node.push_back(root);
            traverse(root->right);
        }
    }

private:
    vector<int> val;
    vector<TreeNode *> node;
};