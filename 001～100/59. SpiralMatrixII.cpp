class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int num = 1;
        int left = 0, right = n - 1;
        int up = 0, down = n -1;
        
        while (left <= right && up <= down) {
            // Traverse right: row == up
            for (int col = left; col <= right; col++) {
                matrix[up][col] = num++;
            }
            if (++up > down) break;
            
            // Traverse down: col == right
            for (int row = up; row <= down; row++) {
                matrix[row][right] = num++;
            }
            if (left > --right) break;

            //Traverse left: row = down
            for (int col = right; col >= left; col--) {
                matrix[down][col] = num++;
            }
            if (up > --down) break;
            
            
            // Traverse up: col = left
            for (int row = down; row >= up; row--) {
                matrix[row][left] = num++;
            }
            if (++left >right) break;
        }
        return matrix;
    }
};