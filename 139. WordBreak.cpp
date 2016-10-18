// Sol1. DFS brute force
// TLE when s.size() > 100
class Solution {
    bool dfs(string s, unordered_set<string>& dict, bool& res, int pos) {
        if (pos == s.size() || res) {
            res = true;
            return true;
        }
        
        for (int i = pos; i < s.size(); i++) {
            if (dict.count(s.substr(pos, i - pos + 1)))
                dfs(s, dict, res, i + 1);
        }
        
        return false;
    }
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        bool res = false;
        dfs(s, wordDict, res, 0);
        return res;
    }
};

////////////////////
// Sol2. DP, avoid duplication
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0) return true;
        if (wordDict.empty()) return false;
        
        bool dp[n + 1]; //dp[i] is true means workable for s[0, i-1]
        fill_n(dp, n + 1, false);
        
        dp[0] = true; //""
        for (int i = 1; i <= n; i++) {
            // find a break point j in [0, i - 1] 
            // where s[0, j - 1] is workable and [j, i] is in dict
            for (int j = 0; j < i; j++) {
                string rest = s.substr(j, i - j);
                if (dp[j] && wordDict.count(rest)){
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
