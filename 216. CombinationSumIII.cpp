class Solution {
    void backtracking(vector<vector<int>>&result, vector<int>&list, int k, int n, int level)
    {
        if (n == 0 && list.size() == k)
        {
            result.push_back(list);
            return;
        }
        
        if (n<0 || list.size() > k) return;
        
        for (int i = level; i <= 9; ++i)
        {
            n -= i;
            list.push_back(i);
            backtracking(result, list, k, n, i+1);
            list.pop_back();
            n += i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> list;
        
        if (n < k || n > 9*k)
            return result;
        
        backtracking(result, list, k, n, 1);
        return result;
    }
};