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
            //different from before:
            //still search in the SAME level it allows multiple use of the letter
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>list;
        sort(candidates.begin(), candidates.end());
        dfs(result, list, candidates, target, 0);
        return result;
        
    }
};