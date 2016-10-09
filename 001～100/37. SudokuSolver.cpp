class Solution {
    bool solveSudoku(vector<vector<char>> &board, int pos, int rowht[9][9], int colht[9][9], int blockht[9][3][3]) {
        if (pos >= 81)
            return true;
        
        int i = pos/9, j = pos % 9;
        
        if (board[i][j] != '.') //when meet a number, move on to next pos
            return solveSudoku(board, pos + 1, rowht, colht, blockht);
        else {
            for (int num = 0; num < 9; num++) {
                //when num isn't in any of the 3 hts, add num to board
                if (!rowht[i][num] && !colht[j][num] && !blockht[num][i/3][j/3]) {
                    board[i][j] = char(num + '1');
                    rowht[i][num] = colht[j][num] = blockht[num][i/3][j/3] = 1;
                    
                    if (solveSudoku(board, pos + 1, rowht, colht, blockht))
                        return true;
                    else { //cannot complete the whole solution, reverse back
                        rowht[i][num] = colht[j][num] = blockht[num][i/3][j/3] = 0;
                        board[i][j] = '.';
                    }
                }
            }
        }
        
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() != 9 || board[0].size() != 9)
            return;
        
        int rowht[9][9] = {{0}}, colht[9][9] = {{0}}, blockht[9][3][3] = {{{0}}};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') { //if meet a number
                    int num = board[i][j] - '1';
                    rowht[i][num] = 1;
                    colht[j][num] = 1;
                    blockht[num][i/3][j/3] = 1;
                }
            }
        }
        solveSudoku(board, 0, rowht, colht, blockht);
    }
};
        
