/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    // 1,2,null,null,3,4,null,null,5,null,null 前序遍历
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> splitted;
        int last = 0;
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == ',') {
                splitted.push_back(data.substr(last, i - last));
                last = i + 1;
            }
        }
        splitted.push_back(data.substr(last));
        this->splitted = splitted;
        this->cur = 0;
        return restore();
    }

    // 1,2,null,null,3,4,null,null,5,null,null
    TreeNode *restore() {
        if (splitted[cur] == "null") {
            cur++;
            return nullptr;
        }
        
        TreeNode *root = new TreeNode(stoi(splitted[cur]));
        cur++;
        TreeNode *left = restore();
        TreeNode *right = restore();
        root->left = left;
        root->right = right;
        return root;
    }

private:
    int cur;
    vector<string> splitted;

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));