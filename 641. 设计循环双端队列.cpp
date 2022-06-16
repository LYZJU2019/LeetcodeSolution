class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        this->capacity = k;
        this->size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = nullptr;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        Node *newnode = new Node();
        newnode->val = value;
        insert(head, newnode);
        this->size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        Node *newnode = new Node();
        newnode->val = value;
        insert(tail->prev, newnode);
        this->size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        remove(head->next);
        this->size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        remove(tail->prev);
        this->size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return head->next->val;
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
private:
    struct Node {
        int val;
        Node *prev;
        Node *next;
    };
    Node *head;
    Node *tail;
    int capacity;
    int size;

    void insert(Node *before, Node *node) {
        before->next->prev = node;
        node->next = before->next;
        before->next = node;
        node->prev = before;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */