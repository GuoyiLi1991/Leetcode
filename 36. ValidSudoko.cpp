class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0}; //9 hash tables respectively
        
        for (int i = 0; i < 9; i++) {    //O(n^2)
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];

                if (c != '.') {
                    int num = c - '1';
                    if (num < 0 || num > 8)
                        return false;
                    
                    int k = i/3 * 3 + j/3; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    if (row[i][num] || col[j][num] || box[k][num])
                        return false;
                    row[i][num] = col[j][num] = box[k][num] = 1;
                }
            }
        }
        return true;
    }
};