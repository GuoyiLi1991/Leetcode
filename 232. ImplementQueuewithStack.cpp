class Queue {
    stack<int> st1, st2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st1.pop();
    }

    // Get the front element.
    int peek(void) {
        return st1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st1.empty();
    }
};


/////////
// With only 1 stack
class Queue {
    stack<int> st;
    void pushHelper(int x) {  //recursive push
        if (st.empty()) {
            st.push(x);
            return;
        }
        
        int tmp = st.top();
        st.pop();
        pushHelper(x);
        st.push(tmp);
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        pushHelper(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        st.pop();
    }

    // Get the front element.
    int peek(void) {
        return st.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st.empty();
    }
};