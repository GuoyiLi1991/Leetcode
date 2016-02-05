class minStack{
    int top;
    priority_queue<int> st;
    
    void push(int x)
    {
        st.push(x);
        top = x;
    }
    
    int pop()
    {
        st.pop();
    }
    
    int top()
    {
        return top;
    }
    
    int getMin()
    {
        return st.front();
    }
    
};