// Find all solutions => DFS, indeed "Subset" problem.
class Solution {
    void dfs(vector<vector<int>> & res, vector<int>&list, vector<int>&candidates, int target, int pos)
    {
        //Terminate cond
        if (target <= 0) 
        {
            if (target == 0)
                result.push_back(list);
            return;
        }
            
        //else, continue recursive dfs
        for (int i = pos; i< candidates.size(); ++i)
        {
            list.push_back(num);
            dfs(result, list, candidates, target - candidates[i], i); 
            //注意这里pos不往前移，当前元素继续被考虑
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>list;
        //无需sort!
        dfs(result, list, candidates, target, 0);
        return result;
        
    }
};