//Solution 1: Recursion
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<1) return false;
        if (n ==1) return true;
        if (n%2) return false;
        return isPowerOfTwo(n/2);
    }
};

//solution2: Bit manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && ((n &(n-1)) ==0);
    }
};

