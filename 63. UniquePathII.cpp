class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int i = 0, j = 0;
        //dp[i][0]
        while (i < m && obstacleGrid[i][0] != 1) {
            dp[i][0] = 1;
            i++;
        }
        //dp[0][j]
        while (j < n && obstacleGrid[0][j] != 1) {
            dp[0][j] = 1;
            j++;
        }
            
        for (i = 1; i < m; i++) {
            for (j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) 
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m-1][n-1];
    }
};