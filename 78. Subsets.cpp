class Solution {
    void helper(vector<vector<int>>&ans, vector<int>&list, vector<int>&nums,int pos)
    {
        ans.push_back(list);
        for (int i = pos; i<nums.size(); i++)
        {
            list.push_back(nums[i]);
            helper(ans, list, nums, i+1);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> list;
        
        sort(nums.begin(), nums.end());
        helper(ans, list, nums, 0);
        return ans;
    }
};