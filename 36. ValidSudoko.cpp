class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int map1[9][9] = {0}, map2[9][9] = {0}, map3[9][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int idx = c - '1';
                    if (idx <0 || idx > 8)
                        return false;
                    map1[i][idx] += 1;  //row
                    map2[idx][j] += 1; //col
                    map3[i/3 * 3 +j/3][idx] += 1; //cube
                    if (map1[i][idx] > 1 || map2[idx][j] > 1 || map3[i/3 * 3 +j/3][idx] >1)
                        return false;
                }
            }
        }
        return true;
    }
};