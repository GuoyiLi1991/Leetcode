class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        
        int l = 0, r = n - 1;
        while (l + 1 < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == target)
                return true;
            if (nums[mid] < nums[l]) { //[l, pivot, mid, r] 
                if (nums[mid] < target && target <= nums[r]) //guarenteed within(mid, r]
                    l = mid;
                else
                    r = mid;
            }
            else if (nums[mid] == nums[l])  //区别：！！此时I里[l, mid)单调递增的假设不成立
                l++;
            else { //[l, mid, pivot, r] 
                if (nums[l] <= target && target < nums[mid]) //guarenteed within[l, mid)
                    r = mid;
                else
                    l = mid;
            }
        }
        if (nums[l] == target || nums[r] == target)
            return true;
        return false;
    }
};
