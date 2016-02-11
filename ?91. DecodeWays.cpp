class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n ==0  || s[0] == '0') return 0;
        
        vector<int> dp(n+1, 0); //TF table
        dp[n] = 1;
        dp[n-1] = (s[n-1] != '0');
        
        for (int i = n-2; i>=0; i--)
        {
            if (s[i] == '0') dp[i] = 0;
            else if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))
                dp[i] = dp[i+1] + dp[i+2];
            else
                dp[i] = dp[i+1];
        }
        
        return dp[0];
        
    }
};