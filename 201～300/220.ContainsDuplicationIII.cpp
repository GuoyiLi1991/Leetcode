class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k == 0)
            return false;
         
        set<long> windows;   
        int l = 0, r = 0;
        while (r < n) {
            if (r - l > k) {
                windows.erase(nums[l++]);
            }
            
            long cur = nums[r];
            auto it = windows.lower_bound((long)cur - (long) t);
            if (it != windows.end() && *it <= ((long)cur + (long)t))
                return true;
            windows.insert(cur);
            r++;
        }
        
        return false;
    }
};