class Solution {
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void markInvalid(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        board[i][j] = '#';
        
        queue<pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            int num = q.size();
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            
            for (int k = 0; k < 4; k++) { //4 directions
                int nx = x + dir[k].first;
                int ny = y + dir[k].second;
                
                if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size())
                    continue;
                if (board[nx][ny] == 'O') {
                    board[nx][ny] = '#';
                    q.push({nx, ny});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;
            
        int m = board.size(), n = board[0].size();
        
        ///////////
        //Invalidate from boarders
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O')
                markInvalid(board, i, 0);
            if (board[i][n - 1] == 'O')
                markInvalid(board, i, n - 1);
        }
        
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O')
                markInvalid(board, 0, j);
            if (board[m - 1][j] == 'O')
                markInvalid(board, m - 1, j);
        }
        
        /////////////
        //Recover
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else 
                    if (board[i][j] == '#')
                        board[i][j] = 'O';
            }
        }
        
    }
};
