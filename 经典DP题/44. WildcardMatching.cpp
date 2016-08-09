////////my versions
class Solution {
    bool isWild(char c) {
        return c == '?' || c == '*';
    }
public:
    bool isMatch(string s, string p) { //1631ms, very slow....
        if (p.empty()) return s.empty();
        if (p == "*") return true;
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        
        f[0][0] = true; // both empty
        //f[i][0]: p is empty but s isn't, by default false 
        //f[0][j]: s is empty, true if p is empty or only contains '*'
        for (int j = 1; j <= n; j++) {
            f[0][j] = f[0][j-1] && p[j-1] == '*';
        }
        
        //i > 0, j > 0
        for (int i = 1; i <= m; i++) 
            for (int j = 1; j <=  n; j++) 
                if (p[j-1] == '?')
                    f[i][j] = f[i-1][j-1];
                else if (p[j-1] == '*')
                    f[i][j] = f[i][j-1] || f[i-1][j] ;
                else
                    f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1]);
                    
        return f[m][n];
    }
};


// TLE now...
    // bool isMatch(string s, string p) {
    //     if (p.empty()) return s.empty();
    //     int m = s.size(), n = p.size();
    //     if (!isWild(p[n-1]) && p[n-1] != s[m-1])
    //         return false;
    //   // if (s.empty()) return p == "" || p == "*";
    //     if (p[0] == s[0] || p[0] == '?') return !s.empty() && isMatch(s.substr(1), p.substr(1));
    //     if (p[0] != '*') return false;
    //     return isMatch(s, p.substr(1)) || !s.empty() && isMatch(s.substr(1), p);
        
    // }