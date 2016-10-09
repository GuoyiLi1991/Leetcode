class Solution {  //84ms, O(1) space, O(mn) time complexity
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); if (!m) return;
        int n = matrix[0].size(); if (!n) return;
        
        unordered_set<int> col;
        unordered_set<int> row;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    col.insert(j);
                    row.insert(i);
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row.find(i) != row.end() || col.find(j) != col.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};


///////////////////
// Same idea but with vector implementation, 76ms
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(); if (!m) return;
        int n = matrix[0].size(); if (!n) return;
        
        vector<bool> col(n, false);
        vector<bool> row(m, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};