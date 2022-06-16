/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<Node *> queue;
        queue.push(root);
        int cur_count = 1, next_count = 0;
        vector<int> temp;

        while (!queue.empty()) {
            cur_count--;
            Node *next = queue.front(); queue.pop();
            temp.push_back(next->val);
            for (Node *child : next->children) {
                queue.push(child);
            }
            next_count += next->children.size();
            if (cur_count == 0) {
                ans.push_back(temp);
                temp.clear();
                cur_count = next_count;
                next_count = 0;
            }
        }

        return ans;
    }
};