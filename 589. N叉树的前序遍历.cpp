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
    vector<int> preorder(Node* root) {
        preorder_helper(root);
        return vec;
    }

    // *****************************************************
    // ************************递归**************************
    // *****************************************************
    void preorder_helper(Node *node) {
        if (node == nullptr) {
            return;
        }
        vec.push_back(node->val);
        for (auto child : node->children)
            preorder_helper(child);
    }

    // ******************************************************
    // ************************迭代（栈）*********************
    // ******************************************************
    void preorder_helper(Node *root) {
        if (root == nullptr) return;
        stack<Node *> stack;
        stack.push(root);

        while (!stack.empty()) {
            Node *node = stack.top(); stack.pop();
            vec.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--)
                stack.push(node->children[i]);
        }
    }

private:
    vector<int> vec {};
};