class MinStack {
public:
    MinStack() {
        data_ = stack<int>();
        min_ = stack<int>();
    }
    
    void push(int val) {
        data_.push(val);
        if (min_.empty())
            min_.push(val);
        else {
            min_.push(min(min_.top(), val));
        }
    }
    
    void pop() {
        data_.pop();
        min_.pop();
    }
    
    int top() {
        return data_.top();
    }
    
    int getMin() {
        return min_.top();
    }

private:
    stack<int> data_;
    stack<int> min_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */