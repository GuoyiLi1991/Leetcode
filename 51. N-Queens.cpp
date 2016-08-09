class Solution {
    bool isValid(vector<string> &sol, int row, int col, int n) { //check if sol[row][col] can place a 'Q'
        int i, j;
        //check columns
        for (i = 0; i < row; i++) {
            if (sol[i][col] == 'Q')
                return false;
        }
        //check 45 degree
        //for (i = 0, j = 0; i < row && j < col; i++, j++) {
        for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (sol[i][j] == 'Q')
                return false;
        }
        //check 135 degree
        for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++ ) {
            if (sol[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void dfs(vector<vector<string>> &res, vector<string> &sol, const int n, int row) {
        if (row == n) {
            res.push_back(sol);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(sol, row, col, n)) {
                sol[row][col] = 'Q';
                dfs(res, sol, n, row + 1);
                sol[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
       // if (n < 3) return res;
        vector<string> sol(n, string(n, '.'));
        dfs(res, sol, n, 0);
        return res;
    }
};

