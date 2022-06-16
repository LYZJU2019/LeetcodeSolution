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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        this->cur = -1;
        inorder(root);
    }
    
    int next() {
        cur++;
        return nodes[cur]->val;
    }
    
    bool hasNext() {
        return cur != nodes.size() - 1;
    }

private:
    vector<TreeNode *> nodes;

    void inorder(TreeNode *root) {
        if (root != nullptr) {
            inorder(root->left);
            nodes.push_back(root);
            inorder(root->right);
        }
    }

    int cur;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */