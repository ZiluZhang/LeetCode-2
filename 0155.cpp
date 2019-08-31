class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> sMin;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (sMin.empty() || x < sMin.top()) sMin.push(x);
        else sMin.push(sMin.top());
    }
    
    void pop() {
        s.pop();
        sMin.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return sMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */