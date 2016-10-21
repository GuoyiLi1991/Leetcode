// Compared to I, matrix[i-1][n-1] is not 
// guarenteed to be smaller than matrix[i][0]
// Sol 1: for each line, use BS
// O(mlogn), Did not take advantage of sorted by cols
class Solution {
    bool BS(vector<int>&v, int target) {
        int l = 0, r  = v.size();
        if (v[l] > target || v[r - 1] < target)
            return false;
        if (v[l] == target || v[r - 1] == target)  
            return true;

        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid] == target)
                return true;
            if (v[mid] < target)
                l = mid + 1;
            else r = mid;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m; i++) {
            if (BS(matrix[i], target))
                return true;
        }
        return false;
    }
};

/// Sol 2. Start from top-right corner, 
//      search either bigger or smaller
// O(m + n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0, j = n - 1; i < m && j >= 0;) {
            if (matrix[i][j] == target)
                return true;
            if (target < matrix[i][j]) //move smaller
                j--;
            else //move bigger
                i++;
        }
        //after m + n steps, still not found
        return false;
    }
};

// Sol 3. Even better! Divide and conqure
// divide the matrix by quardratic
// O(logm + log n)
class Solution {
    bool divide(vector<vector<int>>& matrix, int target, int rowStart, int rowEnd, int colStart, int colEnd) {
        // Termination
        if (rowStart > rowEnd || colStart > colEnd      //illegal index
            || matrix[rowStart][colStart] > target     //min >target
            || matrix[rowEnd][colEnd] < target)        //max < target
            return false;
        
        // Recursive Binary Search
        int rowMid = rowStart + (rowEnd - rowStart) / 2;
        int colMid = colStart + (colEnd - colStart) / 2;
    
        if (matrix[rowMid][colMid] == target)
            return true;
            
        /*
        colS    colM    colEnd
        ----------------- rowStart
        |   1   |   2   |
        ----------------- rowMid
        |   3   |   4   |
        ----------------- rowEnd
        */
        
        if (matrix[rowMid][colMid] < target) // ignore left-above
            return divide(matrix, target, rowMid + 1, rowEnd, colMid + 1, colEnd)    // 4
                || divide(matrix, target, rowStart, rowMid, colMid + 1, colEnd)     // 2 , add rowMid
                || divide(matrix, target, rowMid + 1, rowEnd, colStart, colMid);     // 3, add colMid
                 

        else //ignore right-below
            return divide(matrix, target, rowStart, rowMid - 1, colStart, colMid - 1)   // 1
                || divide(matrix, target, rowStart, rowMid - 1, colMid, colEnd)      // 2, add colMid
                || divide(matrix, target, rowMid, rowEnd, colStart, colMid - 1);    // 3, add rowMid
                
                
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].size() == 0)
            return false;
        int m = matrix.size(), n = matrix[0].size();
        return divide(matrix, target, 0, m - 1, 0, n - 1);
    }

};