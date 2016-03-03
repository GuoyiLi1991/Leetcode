class Solution {
    void backtracking(vector<vector<int>> &result, vector<int> &list, vector<int>&candidates, int target, int level)
    {
        if (target == 0)
        {
            result.push_back(list);
            return;
        }
        
        if (target < 0)
            return;
            
        for (int i = level; i < candidates.size(); ++i)
        {
            int num = candidates[i];
            target -= num;
            list.push_back(num);
            backtracking(result, list, candidates, target, i+1);
            list.pop_back();
            target += num;
            //deal with duplication
            while ( i< candidates.size() && candidates[i+1] == num) i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> list;
        
        sort(candidates.begin(), candidates.end());
        backtracking(result, list, candidates, target, 0);
        
        return result;
    }
};