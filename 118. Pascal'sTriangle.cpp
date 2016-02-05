class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        if (numRows == 0) return result;
        
        for (int i = 1; i<=numRows; i++)
        {
            result[i-1].resize(i);
            result[i-1][0] = result[i-1][i-1] = 1;
            if (i>2)
                for (int j = 0; j<i-1; j++)
                    result[i-1][j] = result[i-2][j-1] + result[i-2][j];
        }
        return result;
    }
};