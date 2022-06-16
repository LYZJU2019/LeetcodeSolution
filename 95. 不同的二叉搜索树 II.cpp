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
    vector<TreeNode*> generateTrees(int n) {
        this->n = n;
        return helper(1, n);
    }

    vector<TreeNode *> helper(int begin, int end) {
        if (begin > end) return {nullptr};

        int hashVal = calcHash(begin, end);
        if (map.find(hashVal) != map.end()) return map[hashVal];

        vector<TreeNode *> ans;
        for (int k = begin; k <= end; k++) {
            auto left_trees = helper(begin, k-1);
            auto right_trees = helper(k+1, end);
            
            for (TreeNode *left : left_trees) {
                for (TreeNode *right : right_trees) {
                    TreeNode *root = new TreeNode(k);    
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        map[hashVal] = ans;
        return ans;
    }

    int calcHash(int begin, int end) {
        return (begin - 1) * n + (end - 1);
    }

private:
    unordered_map<int, vector<TreeNode *>> map;
    int n;
};