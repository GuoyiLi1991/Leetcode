class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; 
        if (n > 10) return 0;

        int dp[11];
    
        dp[0] = 1; //only 0 fits
        dp[1] = 9;
        for (int i = 2; i <= 10; i++) {
            dp[i] = dp[i - 1] * (9 - i + 2);
            if (n == i)
                break;
        }
        int res = 0;
        for (int i = 0; i <= n; i++) {
            res += dp[i];
        }
        return res;
    }
};