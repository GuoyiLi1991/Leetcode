class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 1));
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};

//空间复杂度的优化
// 去掉i维度
class Solution {
public:
    int uniquePaths(int m, int n) {
        int ways_to_cur_col[n];
        fill_n(ways_to_cur_col, n, 0);
        ways_to_cur_col[0] = 1;
        for (int i = 0; i < m; i++) 
            for (int j = 1; j < n; j++)
                ways_to_cur_col[j] += ways_to_cur_col[j-1];
        return ways_to_cur_col[n-1];
    }
};