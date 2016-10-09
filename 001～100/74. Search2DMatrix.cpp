//////////
// Sol1. Find the row in linear time, and do BS to the row
// O(m + logn), 9ms
class Solution {
    bool BinarySearch(vector<int> v, int target)
    {
        int l = 0, r = v.size();
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if (v[mid] == target)
                return true;
            else if (v[mid] < target)  //search right of mid
                l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        while (row < m && matrix[row][n-1] < target)
            row++;
        if (row == m) return false;

        return BinarySearch(matrix[row], target);
    }
};

///////////////////////////
// Sol 2. Do BS to both rows and cols
 class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m=matrix.size();
            if(!m)  return false;
            int n=matrix[0].size();
            /*** binary-search the line-index ***/
            int start=0, end=m, mid;
            /*** [start, end) ***/
            while(end-start > 1){
                mid=(start+end)/2;
                if(matrix[mid][0]<=target)  start=mid;
                else //if(matrix[mid][0]>target)  
                    end=mid;
            }
            int row=start;
            cout<<"row:"<<row<<endl;
            /*** binary-search the line-index ***/
            start=0;
            end=n;
            /*** [start, end) ***/
            while(end-start > 1){
                mid=(start+end)/2;
                if(matrix[row][mid]<=target)  start=mid;
                else if(matrix[row][mid]>target)  end=mid;
            }
            return matrix[row][start]==target;
    }
};

///////////
// Redo
class Solution {
    bool BS(vector<int>& v, int target) {
        int l = 0, r = v.size() - 1;
        if (v[l] > target || v[r] < target)
                return false;
        while (l + 1 < r) {
            int mid = l + (r - l)/2;
            if (v[mid] == target)
                return true;
            if (v[mid] < target)
                l = mid;
            else 
                r = mid;
        }
        if (v[l] == target || v[r] == target)
            return true;
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return -1;
        int n = matrix[0].size();
        if (n == 0) return -1;
        
        for (int i = 0; i < m; i++)
            if (BS(matrix[i], target))
                return true;
        
        return false;
     }
};


///////////
// Sol3: 2D->1D, do binary search
// Time: O(log(mn))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        //corner case:
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
            return false;
        //general binary search
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;
            int tmp = matrix[row][col];
            
            if (tmp == target)
                return true;
            if (tmp > target) //search left
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return false;
        
    }
};

