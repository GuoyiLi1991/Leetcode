https://discuss.leetcode.com/topic/23408/dynamic-programming-c-o-n-time-o-1-space-0ms
class Solution {
public:
    int numWays(int n, int k) {
        if (n < 2 || !k) return n * k; 
        int s = k, d1 = k, d2 = k * (k - 1); 
        for (int i = 2; i < n; i++) {
            s = d2;
            d2 = (k - 1) * (d1 + d2);
            d1 = s;
        }
        return s + d2;
    }
};