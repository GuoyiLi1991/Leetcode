class Solution {
public:
    int integerBreak(int n) {
        if (n < 3) return 1;
        int dp[n];
        fill_n(dp, n, 0);
        /* eg.
        1 = 1
        2 = 1 + 1, 1, 3^0
        
        3 = 2 + 1, 2
        
        4 = 2 + 2 > 3 + 1, 4 = 2 * 2
        5 = 2 + 3, 6 = 2 * 3
        6 = 3 + 3, 9 = 3 ^ 2
        
        7 = 2 + (2 + 3), 12 = 6 * 2 = 3 * 4
        8 = 2 + (3 + 3), 18 = 6 * 3 = 3 * 6
        9 = 3 + (3 + 3), 27 = 3 ^ 3
        
        10 = 2 + (3 + 2 + 3), 36 = 3 * 12
        11 = 2 + 9, 54 = 18 * 3 = 2 * 27
        12 = 3 + 3 + 3 + 3, 81 = 3^4
        
        13 = 2 + 2 + 3 * 3, 108 = 4 * dp[8]
        ....
        */
        dp[0] = 1; //1 = 1
        dp[1] = 1; //2 = 1 + 1
        if (n <= 2) return dp[n - 1];
        dp[2] = 2; //3 = 2 + 1
        for (int i = 3; i < n; i++) {
            if (i == 3) {
                dp[3] = 4;
                continue;
            }
            if (i == 4) {
                dp[4] = 6;
                continue;
            }
            // max product for number (i + 1)
            int num = i + 1;
            if (num % 3 == 0) //multiple of 3
                dp[i] = pow(3, num/3);
            else if (num % 3 == 1)
                dp[i] = 4 * max(num - 4, dp[i - 4]);
            else
                dp[i] = 2 * max(num - 2, dp[i - 2]);
        }
        return dp[n - 1];
    }
};