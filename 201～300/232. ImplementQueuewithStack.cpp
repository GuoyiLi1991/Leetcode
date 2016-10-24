/// Sol1. Using two stacks
// Sol1-1: 
// Push: O(n^2), others all O(1)
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

// Sol1-2:
// Push() & empty() O(1)
// Pop() and peek() worst O(n), average O(1)
class Queue {
    stack<int> stOld;
    stack<int> stNew;
    
public:
    // Push element x to the back of queue.
    void push(int x) {
        stNew.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (stOld.empty()) {
            while (!stNew.empty()) {
                stOld.push(stNew.top());
                stNew.pop();
            }
        }
        stOld.pop();
    }

    // Get the front element.
    int peek(void) {
        if (stOld.empty()) {
            while (!stNew.empty()) {
                stOld.push(stNew.top());
                stNew.pop();
            }
        }
        return stOld.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stOld.empty() && stNew.empty();
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