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

///////////// Two pointers
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>{});
        if (numRows == 0) return res;
        for (int i = 0; i < numRows; i++) {
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            if (i >= 2) {
                int l = 1, r = i - 1;
                while (l <= r) {
                    res[i][l] = res[i][r] = res[i-1][l-1] + res[i-1][l];
                    l++;
                    r--;
                }
            }
        }
        
        return res;
        
        
    }
};