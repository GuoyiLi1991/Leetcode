// DFS, no need sorting
// O(2^n), each number has 2 options:chosen or not
class Solution {
    void dfs(vector<vector<int>>&res, vector<int>&list, vector<int>&nums,int pos)
    {
        res.push_back(list);
        for (int i = pos; i<nums.size(); i++)
        {
            list.push_back(nums[i]);
            dfs(res, list, nums, i+1); //choose from the rest
            list.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list;
        
        dfs(res, list, nums, 0);
        return res;
    }
};