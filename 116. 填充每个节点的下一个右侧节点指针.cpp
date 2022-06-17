/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        connect_helper(root->left, root->right);
        return root;
    }

    void connect_helper(Node *left, Node *right) {
        if (left == nullptr) return;
        left->next = right;
        connect_helper(left->left, left->right);
        connect_helper(right->left, right->right);
        connect_helper(left->right, right->left);
    }
};