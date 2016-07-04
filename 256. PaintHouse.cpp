class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n ==0) return 0;
        
        vector<vector<int>> dp(n+1, vector<int>(3,0));
        
       // dp[0] = costs[0];
        for(int i = 0; i<n; ++i)
        {
            dp[i+1][0] = costs[i][0] + min(dp[i][1], dp[i][2]);
            dp[i+1][1] = costs[i][1] + min(dp[i][0], dp[i][2]);
            dp[i+1][2] = costs[i][2] + min(dp[i][0], dp[i][1]);
        }
        
        return min(min(dp[n][0], dp[n][1]), dp[n][2]);
        
    }
};