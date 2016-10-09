class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        // int i = 0;  //O(n)
        // while (i < n && nums[i] < target) {
        //     i++;
        // }
        // return i;
        
        int l = 0, r = n-1;  //Binary Search: O(log n)
        while (l <=  r) {
            int mid = r - (r-l)/2;
            if (nums[mid] < target)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        // possible result is from [l, r+1]
        // until this point, l > r <=> l >= r + 1
        // thus l == r + 1
        return l;
    }
};