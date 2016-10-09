class PhoneDirectory {
    int max_num, next, idx;
    vector<int> flag, recycled;
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers): max_num(maxNumbers), next(0), idx(0) {
        flag.resize(maxNumbers, 1);
        recycled.resize(maxNumbers);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next == max_num && idx <= 0) 
            return -1;
        if (idx > 0) {
            int t = recycled[--idx];
            flag[t] = false;
            return t;
        }
        flag[next] = false;
        return next++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return (number >= 0 && number < max_num && flag[number]);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number >= 0 && number < max_num && !flag[number]) {
            flag[number] = true;
            recycled[idx++] = number;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
 