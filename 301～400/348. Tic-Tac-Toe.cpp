class TicTacToe {
    vector<vector<int>> board;
    int win(vector<vector<int>>& board, int row, int col) {
        int n = board.size();
        int player = board[row][col];
        
        //horizontal or vertical
        int delta = 1;
        while (delta < n) {
            if (board[(row + delta) % n][col] != player)
                break;
            delta++;
        }
        if (delta == n) return player;
        
        delta = 1;
        while (delta < n) {
            if (board[row][(col + delta) % n] != player)
                break;
            delta++;
        }
        if (delta == n) return player;
            
        //45 degrees
        delta = 1;
        if (row == col) {
            while (delta < n) {
                if (board[(row + delta) % n][(col + delta) % n] != player)
                    break;
                delta++;
            }
        }
        if (delta == n) return player;
        
        //135 degrees  
        delta = 1;
        if (row + col == n - 1) {
            while (delta < n) {
                if (board[(row + delta) % n][(col + n - delta) % n] != player)
                    break;
                delta++;
            }
        }
        if (delta == n) return player;
           
        return 0;
    }
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int>(n, -1));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        return win(board, row, col);
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */