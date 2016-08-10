class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        int left[n], right[n], height[n];
        int maxArea = 0;
        
        fill_n(left, n, 0);
        fill_n(right, n, n);
        fill_n(height, n, 0);
        
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            //compute left: from left to right
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], cur_left);
                }
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }
            
            //compute right: from right to left
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }
            
            //compute height: can do from both sides
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            //compute max area until cur row
            for (int j = 0; j < n; j++)
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
        return maxArea;
    }
};