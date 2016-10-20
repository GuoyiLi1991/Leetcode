class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
            
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        
        //rows
        int enemy_killed_row[m][n]; //<num_enemy, valid_until>
        for (int i = 0; i < m; i++) {
            vector<char> row = grid[i];
            int cnt = 0;
            int l = 0, r = 0;
            while (r <= n) {
                if (r == n || row[r] == 'W') {
                    for (int j = l; j < r; j++)
                        enemy_killed_row[i][j] = cnt;
                    cnt = 0;
                    if (r != n) enemy_killed_row[i][r] = INT_MIN;
                    l = r + 1;
                }
                if (r != n && row[r] == 'E')
                    cnt++;
                r++;
            }
        }
        
        //cols
        int enemy_killed_col[m][n]; //<num_enemy, valid_until>
        
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            int up = 0, down = 0;
            while (down <= m) {
                if (down == m || grid[down][j] == 'W') {
                    for (int i = up; i < down; i++)
                        enemy_killed_col[i][j] = cnt;
                    cnt = 0;
                    if (down != m) enemy_killed_col[down][j] = INT_MIN;
                    up = down + 1;
                }
                if (down != m && grid[down][j] == 'E')
                    cnt++;
                down++;
            }
        }
        
        //combine row and col
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')
                    res = max(enemy_killed_col[i][j] + enemy_killed_row[i][j], res);
            }
        }
        return res;
    }
};