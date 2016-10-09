class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        if (n == 0) return 0;
        int k = costs[0].size();
        if (k == 0) return 0;
        
        vector<int> dp(k, 0);
        int min1 = 0, min2 = 0;
        int min1_old , min2_old ;
        for (int i = 0; i<n; ++i)
        {
            min1_old = min1;
            min2_old = min2;
            min1 = INT_MAX;
            min2 = INT_MAX;
            
            for (int j = 0; j<k; ++j)
            {
                if (dp[j] != min1_old)
                    dp[j] = costs[i][j] + min1_old;
                else
                    dp[j] = costs[i][j] + min2_old;
                    
                //update min1, min2
                if (dp[j] < min1)
                {
                    min2 = min1;
                    min1 = dp[j];
                }
                else
                    min2 = min(min2, dp[j]);
            }
        }
        
        return min1;
        
    }
};