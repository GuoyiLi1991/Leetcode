class MinStack {
    stack<int> minStack;
    stack<int> mainStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
        mainStack.push(x);
    }
    
    void pop() {
        if (mainStack.top() == getMin())
            minStack.pop();
        mainStack.pop();
    }
    
    int top() {
        if (!mainStack.empty())
            return mainStack.top();
        else return -1;
    }
    
    int getMin() {
        if (!minStack.empty())
            return minStack.top();
        else return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */