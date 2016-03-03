class Solution {
    void backtracking(vector<vector<int>> & result, vector<int>&list, vector<int>&candidates, int target, int level)
    {
        //base case
        if (target == 0) //found
        {
            result.push_back(list);
            return;
        }
        
        if (target < 0)  //invalid combination
            return;
            
        //recursive
        for (int i = level; i< candidates.size(); ++i)
        {
            int num = candidates[i];
            list.push_back(num);
            target -= num;
            backtracking(result, list, candidates, target, i); 
            //different from before:
            //still search in the same level it allows multiple use of the letter
            target += num;
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>list;
        sort(candidates.begin(), candidates.end());
        backtracking(result, list, candidates, target, 0);
        return result;
        
    }
};