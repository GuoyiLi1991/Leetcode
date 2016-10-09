class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res{-1, -1};
        if (n == 0) return res;
        int l = 0, r = n-1;
        if (nums[l] > target || nums[r] < target)
            return res;
        //find starting point
        int mid = 0;
        while ( l <= r) {
            mid = l + (r-l)/2;
            if (nums[mid] < target)
                l = mid +1;
            else if (nums[mid] > target)
                r = mid -1 ;
            else break;
        }
        
        if (nums[mid] != target) return res;
        
        int start = mid;
        int end = mid;
        while (start > 0 && nums[start-1] == nums[start])
                    start--;
        while (end < n - 1 && nums[end+1] == nums[end])
                    end++;
        res[0] = start;
        res[1] = end;
        return res;
    }
};

////////////////////////////////////////////////////
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res{-1, -1};
        if (n == 0) return res;
        int l = 0, r = n-1;
        if (nums[l] > target || nums[r] < target)
            return res;
        //find starting point
        int mid = 0;
        while ( l <= r) {
            mid = l + (r-l)/2;
            if (nums[mid] < target)
                l = mid +1;
            else if (nums[mid] > target)
                r = mid -1 ;
            else if (mid > 0 && nums[mid-1] == nums[mid])
                r = mid -1;
            else break;
        }
        if (nums[mid] != target) return res;
        res[0] = mid;
        
        //find ending point
        l = 0; r = n-1;
        while ( l <= r) {
            mid = l + (r-l)/2;
            if (nums[mid] < target)
                l = mid +1;
            else if (nums[mid] > target)
                r = mid -1 ;
            else if (mid < n-1 && nums[mid+1] == nums[mid])
                l = mid +1;
            else break;
        }
        res[1] = mid;
        return res;
    }
};