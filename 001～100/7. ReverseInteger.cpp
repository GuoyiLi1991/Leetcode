class Solution {
public:
    int reverse(int x) {
        long res = 0;
        
        int d = x % 10;
        while (x) {
            res = res * 10 + d;
            x /= 10;
            d = x % 10;
        }
        
        return (res < -INT_MAX || res>INT_MAX)? 0: res;
    }
};