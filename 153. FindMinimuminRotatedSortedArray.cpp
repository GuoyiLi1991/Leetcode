////////
// Sol1: One pass
// Time: O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int i = 0;
        while (i < n - 1 && nums[i] < nums[i + 1])
            i++;
        
        if (i == n - 1) //monotone increasing
            return nums[0];
        
        return nums[i + 1];
    }
};

///////
// Sol2: Binary Search: Find i when nums[i] < nums[i - 1]
// Time: O(log n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (nums[0] < nums[n - 1]) //monotone increasing
            return nums[0];
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) /2;
            if (nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[r] < nums[mid]) //search right
                l = mid + 1;
            else    //search left
                r = mid;
        } // l == r
        return nums[l];
    }
};
