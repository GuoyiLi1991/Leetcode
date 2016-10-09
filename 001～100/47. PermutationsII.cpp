class Solution {
    void backtracking(vector<vector<int>> &result, vector<int>&list, vector<int>&nums, vector<bool> &visited)
    {
        if (list.size() == nums.size())
        {
            result.push_back(list);
            return;
        }
        for (int i = 0; i< nums.size(); i++)
        {
            if (visited[i] ==  false)
            {
                list.push_back(nums[i]);
                visited[i] = true;
                backtracking(result, list, nums, visited);
                visited[i] = false;
                list.pop_back();
                /*******deal with duplication***********/
                while( i<nums.size()-1 && nums[i] == nums[i+1])
                    i++;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        
        vector<bool> visited(nums.size(), false);
        /*******deal with duplication***********/
        sort(nums.begin(), nums.end());
        backtracking(result, list, nums,visited);
        
       // set<vector<int>> uniq(result.begin(), result.end());
        //result = *(new vector<vector<int>>(uniq.begin(), uniq.end()));
        return result;
    }
};