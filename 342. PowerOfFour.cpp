class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 1) return true;
        if (num <= 0 || num % 4) return false;
        return isPowerOfFour(num/4);
    }
};

// No recursion/loop
// Proof: 4^n - 1 = 4
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num >= 1 && (num & (num-1))== 0 && (num-1) % 3 == 0);
    }
};


class Solution {
public:
    bool isPowerOfFour(int num) {
        bool result = false;
        for (int i = 0; i < 32; i++) {
            if (((num>>i) & 1)>0)
            {
                if (result == true)
                    return false;
                if (i % 2) 
                    return false;
                result = true;
            }
        }
        return result;
    }
};