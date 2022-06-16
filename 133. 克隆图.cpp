/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // 只有当图为空时才有效
        if (node == nullptr) return node;
        // 该节点已经被克隆过
        if (map.find(node->val) != map.end()) return map[node->val];
        Node *newroot = new Node(node->val);
        // 如果放在for循环之后会死循环，因为这是递归终止的条件
        map[node->val] = newroot;
        for (Node *neighbor: node->neighbors) {
            Node *new_nei = cloneGraph(neighbor);
            newroot->neighbors.push_back(new_nei);
        }
        return newroot;
    }

private:
    unordered_map<int, Node *> map;
};