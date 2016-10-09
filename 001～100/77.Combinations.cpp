class Solution {
    void DFS(vector<vector<int>> &result, vector<int>&list, int n, int pos, int k)
    {
        if (list.size() == k) 
        {
            result.push_back(list);
            return;
        }
        for (int i =pos; i <= n; ++i )
        {
            list.push_back(i);
            DFS(result, list, n, i+1, k);
            list.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> list;
        DFS(result, list, n, 1, k);
        return result;
        
    }
};