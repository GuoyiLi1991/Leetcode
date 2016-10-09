class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        
        unordered_map<int, int> mp; // <num, idx>
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i]) == mp.end()) //not found
                mp[nums[i]] = i;
            else {
                if (i - mp[nums[i]] <= k)
                    return true;
                else
                    mp[nums[i]] = i;
            }
        }
        return false;
    }
};