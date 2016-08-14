class Solution {
public:
    int numSquares(int n) {
        int k = sqrt(n);
        int coins[k];
        for (int i = 0; i < k; i++) {
            coins[i] = (i + 1) * (i + 1);
        }
        int dp[n + 1];
        int Max = n + 1;
        fill_n(dp, n + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++)
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i-coins[j]]+ 1, dp[i]);
        return dp[n];
    }
};