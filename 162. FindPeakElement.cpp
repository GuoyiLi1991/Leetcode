///////////////
// Sol 1: One pass O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1 || nums[0]>nums[1]) return 0;
        
        int i;
        for (i = 1; i< nums.size()-1; i++)
        {
            if (nums[i] > nums[i-1] && nums[i]>nums[i+1])
                return i;
        }
        return i;
        
    }
};

/////////
// Sol 2-1: Binary Search O(lg n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {        
        int n = nums.size();
        if (n < 2 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return (n - 1);
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid + 1]) //search right half
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};

//////////
// Sol 2-2 : kind of binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n-1;
        while (l<r)
        {
            int mid = l+(r-l)/2;
            if (nums[mid] > nums[mid+1]) //search left half
                r = mid;
            else l = mid+1;
        }
        return l;
    }
};


/////=======================================//
// Follow up: 
// Given a matrix(最外周比次外周小）, find peak element
// A[i][j] > A[i + 1][j]
// A[i][j] > A[i - 1][j]
// A[i][j] > A[i][j + 1]
// A[i][j] > A[i][j - 1]


// Sol1 : 暴力搜索（O(4mn))
// Sol2 : 选行／列 一个维度进行二分＝》如果只是局部最优解，可能会绕圈，不可行
// sol3 : 找第m/2行“整行最大值”：纵向比较：O(nlogm)
// if (a[i][j] < a[i + 1][j]) search in the upper half
// if (a[i][j] < a[i - 1][j]) search in the lower half
// if (a[i][j] > a[i + 1][j] && a[i][j] > a[i - 1][j]) return
// 进一步优化：行列两个维度都二分＝》线性复杂度
// T(nm) = m + n/2 + T(m/2 * n/2) 
//        = m(1 + 1/2 + 1/4+....) + n(1/2+1/4+...) 
//        = O(2m + n)
