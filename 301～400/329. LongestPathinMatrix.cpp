// memorization + DFS
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {-1, 1, 0, 0};

class Solution {
    int dfs(vector<vector<int>>& matrix, int m, int n, vector<vector<int>>& dict, int x, int y) {
        if (dict[x][y]) return dict[x][y];
        
        for (int i = 0; i < 4; i++) {
            //neighbour index
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && //within valid range
                matrix[nx][ny] > matrix[x][y]) //increasing
                dict[x][y] = max(dict[x][y], dfs(matrix, m, n, dict, nx, ny));
        }
        
        return ++dict[x][y];
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dict(m, vector<int>(n, 0));
        int res = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(matrix, m, n, dict, i, j));
            }
        }
        return res;
    }
};

