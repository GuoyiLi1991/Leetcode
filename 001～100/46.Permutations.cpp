class Solution {
    void backtracking(vector<vector<int>> &result, vector<int>&list, vector<int>&nums, vector<bool> &visited)
    {
        if (list.size() == nums.size())
        {
            result.push_back(list);
            return;
        }
        for (int i = 0; i< nums.size(); i++)  //i from 0
        {
            if (visited[i] ==  false)
            {
                list.push_back(nums[i]);
                visited[i] = true;
                backtracking(result, list, nums, visited);
                visited[i] = false;
                list.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        
        vector<bool> visited(nums.size(), false);
        backtracking(result, list, nums,visited);
        
        return result;
    }
};