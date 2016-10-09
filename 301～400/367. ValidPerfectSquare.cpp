class Solution {
public:
    // Binary search O(log n)
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 0, r = num;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (mid * mid == num)
                return true;
            if (num / mid >= mid)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        return false;
    }
};

// Another solution: O(sqrt(n)) slower than BS
    bool isPerfectSquare(int num) {
        /* 1 = 1
            4 = 1 + 3
            9 = 1 + 3 + 5
            16 = 1 + 3 + 5 + 7
            n * n = 1 + ... + (2n - 1) = (1 + 2n-1) * n /2 
        */
        int i = 1;
        while (1) {
            if (num == 0) return true;
            if (num < 0) return false;
            num -= i;
            i += 2;
        }
    }