class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        
        unordered_set<int> ht;
        for (int i = 0; i < n; i++) {
            if (ht.find(nums[i]) != ht.end())
                return true;
            ht.insert(nums[i]);
        }
        return false;
    }
};