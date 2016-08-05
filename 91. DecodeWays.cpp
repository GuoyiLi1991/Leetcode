// Brute Force: using recursion => TLE
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        if (s[0] == '0')
            return 0;
            
        if (n == 1)
            return 1;

        if (s[0] == '1' || (s[0] == '2' && s[1] <= '6')) {
            if (s.size() >2)
                return numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            else
                return numDecodings(s.substr(1)) + 1;
        }

        return numDecodings(s.substr(1));
    }
};

// DP
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return (s[0]!= '0');
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0');
        
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0')
                dp[i] = 0;
            else if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else
                dp[i] = dp[i + 1];
            
        }
        return dp[0];
    }
};