class Stack {
    queue<int> q, qq;
public:
    // Push element x onto stack.
    void push(int x) {
        while (!q.empty()) {
            qq.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!qq.empty()) {
            q.push(qq.front());
            qq.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};

////////
// With only 1 queue. 
class Stack {
    queue<int> q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};