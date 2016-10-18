//相同元素只能最多取freq次
// 1. dfs之前要sort
// 2. dfs时 pos = i + 1
// 3. bt之后while循环跳过重复元素
class Solution {
    void dfs(vector<vector<int>> & res, vector<int> & list, vector<int>&candidates, int target, int pos) {
        //termination cond.
        if (target <= 0) {
            if (target == 0)
                res.push_back(list);
            return;
        }
        
        //else, dfs
        for (int i = pos; i < candidates.size(); i++) {
            list.push_back(candidates[i]);
            dfs(res, list, candidates, target - candidates[i], i + 1);
            list.pop_back();
            
            while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i])
                i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> list;
        //要sort!
        sort(candidates.begin(), candidates.end());
        dfs(res, list, candidates, target, 0);
        return res;
    }
};