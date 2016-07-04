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


//Another bit manipulation: allows one and only one 1
class Solution {
public:
    bool isPowerOfTwo(int n) {  
        bool result = false;
        while (n) {
            if ((n & 1) ==1) {
                if (result)
                    return false;
                else
                    result = true;
            }
            n = n >>1;
            
        }
        return result;
    }
};
