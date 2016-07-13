class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy = matrix;//(n, vector<int>(n, 0));
        
        for (int i =0 ; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = copy[n-1-j][i];
            }
        }
    }
};


///////////// in place ///////////////
// flip by the line x = y, then flip horizontally ///////
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();        

        for (int i =0 ; i < n; i++) {
            for (int j = i; j < n; j++) {
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for (int i =0 ; i < n; i++) {
            //reverse(matrix[i].begin(), matrix[i].end());
            for (int j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n-1-j]); //horizontally flip
            }
        }
        
    }
};