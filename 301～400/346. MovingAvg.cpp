class MovingAverage {
    queue<int> q;
    int capacity;
    double avg;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        capacity = size;
    }
    
    double next(int val) {
        int n = q.size();
        if (q.size() < capacity) {
            avg = (avg * n + val) / (n + 1);
        }
        else {
            avg = (avg * n - q.front() + val) / n;
            q.pop();
        }
        
        q.push(val);
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */