class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty() || B.empty()) return res;
        
        int r1 = A.size(), c1 = A[0].size(), c2 = B[0].size();
        //A is [r1 * c1], B is [c1 * c2]
        //res is [r1 * c2]

        res.resize(r1, vector<int>(c2, 0));
        for (int i = 0; i < r1; i++) {
            for (int k = 0; k < c1; k++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < c2; j++) {
                        if (B[k][j] != 0)
                            res[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return res;
    }
};