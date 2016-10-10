// Consider duplication
// 1. must sort
// 2. while (i < nums.size() - 1 && nums[i + 1] == nums[i]) i++;
class Solution {
    void dfs(vector<vector<int>>& res, vector<int>& set, vector<int>& nums, int pos) {
        res.push_back(set);

        for (int i = pos; i < nums.size(); i++) {
            set.push_back(nums[i]);
            dfs(res, set, nums, i + 1);
            set.pop_back();

            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                i++;
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> set;

        sort(nums.begin(), nums.end());
        dfs(res, set, nums, 0);

        return res;
    }
};