class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(); if (!m) return res;
        int n = matrix[0].size(); if (!n) return res;
        
        int left = 0, right = n-1;
        int up = 0, down = m -1;
        
        while (left <= right && up <= down) {
            // Traverse right: row == up
            for (int col = left; col <= right; col++) {
                res.push_back(matrix[up][col]);  
            }
            if (++up > down) break;
            
            // Traverse down: col == right
            for (int row = up; row <= down; row++) {
                res.push_back(matrix[row][right]);
            }
            if (left > --right) break;

            //Traverse left: row = down
            for (int col = right; col >= left; col--) {
                res.push_back(matrix[down][col]);
            }
            if (up > --down) break;
            
            
            // Traverse up: col = left
            for (int row = down; row >= up; row--) {
                res.push_back(matrix[row][left]);
            }
            if (++left >right) break;
        }
        
        return res;
    }
};