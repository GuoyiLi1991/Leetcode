class Solution {
    void helper(vector<vector<int>> &ans, vector<int>&list, vector<int> &nums, int pos)
    {
        ans.push_back(list);
        
        for (int i = pos; i<nums.size(); i++)
        {
            // deal with duplication
            if (i>pos && nums[i-1] == nums[i])
                continue;
            list.push_back(nums[i]);
            helper(ans, list, nums, i+1);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        
        if (nums.size() == 0)
            return ans;
            
        vector<int> list;
        sort(nums.begin(), nums.end());
        
        helper(ans, list, nums, 0);
        return ans;
        
    }
};



///////// Redo
class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& set, vector<int>& nums, int pos) {
        res.push_back(set);
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i - 1])
                continue;
            set.push_back(nums[i]);
            dfs(res, set, nums, i + 1);
            set.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> set;
        dfs(res, set, nums, 0);
        return res;
    }
};