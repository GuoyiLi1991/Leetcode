//////
// Sol1: create a NodewithMin class
// each node has a property of the min until now
// Not space efficient. eg. the bottom node is the smallest,
//    then we wasted space to store it with every node
class NodewithMin{
  int value;
  int min;
public:
    NodewithMin(int v, int m):value(v), min(m){};
    int getValue() const {return value;}
    int getMin() const{return min;}
};

class MinStack {
   // int curMin;
    stack<NodewithMin> st;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (st.empty())
            st.push(NodewithMin(x, x));
        else {
            st.push(NodewithMin(x, min(x, st.top().getMin())));
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().getValue();
    }
    
    int getMin() {
        return st.top().getMin();
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
// Same with having two stacks underneath: values and mins
class MinStack {
    stack<int> values;
    stack<int> mins;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        values.push(x);
        if (mins.empty())
            mins.push(x);
        else
            mins.push(min(x, mins.top()));
    }
    
    void pop() {
        values.pop();
        mins.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return mins.top();
    }
};


/////////
// Sol2: more space efficient:
// Only update the min stack (state) when a smaller element
//    is pushed/popped

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
        if (mainStack.top() == minStack.top())
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