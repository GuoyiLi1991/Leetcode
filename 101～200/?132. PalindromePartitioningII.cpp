// min/max DP
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));// fill forwards
        vector<int> minCut(n + 1); // min cut for s[i, i + 1, ..., n], fill backwards
        for (int i = 0; i <= n; i++)
            minCut[i] = n - i - 1;
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if ((i + 1 >= j - 1 || isPalin[i + 1][j - 1]) && s[i] == s[j]) {
                    isPalin[i][j] = true;
                    minCut[i] = min(minCut[j + 1] + 1, minCut[i]);
                }
            }
        }
        
        return minCut[0];
    }
};


