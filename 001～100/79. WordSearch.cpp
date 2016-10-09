// DFS, combination problem
// Time complexity: O(m*n*4^length)
// In place
class Solution {
    bool helper(vector<vector<char>>& board, int i, int j,  string word,int length)
    {
        /*** terminating cases ***/
        if (length == word.size()) //found
            return true;
        
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) //not found 
            return false;
            
        if (board[i][j] == '*' || board[i][j] != word[length])
            return false;
        
        /*** board[i][j] matches word[length], recursive search ***/
        char tmp = board[i][j];
        board[i][j] = '*';
        bool result = helper(board, i-1, j, word, length+1) 
                    || helper(board, i+1, j, word, length+1)
                    || helper(board, i, j+1, word, length+1)
                    || helper(board, i, j-1, word, length+1);
        board[i][j] = tmp;
        
        return result;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (helper(board, i, j, word, 0)) 
                    return true;
            }
            
        return false;
        
    }
};