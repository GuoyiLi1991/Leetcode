// Brute Force: using recursion => TLE (exponential time)
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

// DP O(n)
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

//////// Another solution: similar to Fibonacci Number
// Directly changed from 70. Climing ladder
class Solution {
    bool isValid(char c) {
        return (c != '0');
    }
    
    bool isValid(char a, char b) {
        return (a == '1' || (a == '2' && b <= '6'));
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (s[0] == '0') return 0;
        if (n == 1) return 1;
        
        int fn_1 = 1, fn_2 = 1;
        for (int i = 1; i < n; i++) {
            bool b1 = isValid(s[i]);  // current is valid
            bool b2 = isValid(s[i-1], s[i]); // current can be combined with next
            
            int res = b1 * fn_1 + b2 * fn_2;
            if (res == 0) return 0;
            fn_2 = fn_1;
            fn_1 = res;
        }
        return fn_1;
    }
};

