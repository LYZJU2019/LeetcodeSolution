class LRUCache {
public:
    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = nullptr;
        this->capacity = capacity;
    }

    // find Node * if exist
    // delete that Node
    // re-insert at head (front)
    int get(int key) {
        if (map.find(key) == map.end()) return -1;
        Node *node = map[key];
        remove(node);
        insert(head, node);
        return node->val;
    }
    
    // find Node *
    // if exist, change value
    // if not, check capacity
    // if overflow, delete tail element
    // insert at head
    void put(int key, int value) {
        if (map.find(key) == map.end()) {
            if (this->capacity == map.size()) {
                map.erase(tail->prev->key);
                remove(tail->prev);
            }
            Node *newnode = new Node();
            newnode->key = key;
            newnode->val = value;
            map[key] = newnode;
            insert(head, newnode);
        } else {
            Node *node = map[key];
            node->val = value;
            remove(node);
            insert(head, node);
        }
    }

private:
    struct Node {
        int key;
        int val;
        Node *prev;
        Node *next;
    };
    Node *head;
    Node *tail;
    unordered_map<int, Node *> map;  // given a key, return the pointer to that Node
    int capacity;

    void insert(Node *prev, Node *node) {
        prev->next->prev = node;
        node->next = prev->next;
        prev->next = node;
        node->prev = prev;
    } 

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */