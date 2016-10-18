///// Sol 1: recursive DFS
class Solution {
public:
    bool isMatch(string s, string p) { //636ms
        if (p.empty()) return s.empty();
        
        if (p[1] != '*')
            return !s.empty() && (p[0] == s[0] || p[0] == '.') 
            && isMatch(s.substr(1), p.substr(1)); //move together
        else
            return isMatch(s, p.substr(2)) ||  // * means 0
                (!s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p)); // * means >= 1 times
    }
};

/////// Sol 2: Dynamic programming : 16ms
class Solution {
public:
    
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false)); //f[i][j]: if s[0...i-1] matches p[0...j-1]
        
        f[0][0] = true; //both are empty strings
        // f[i][0] :p is empty but s is not, by default false for i within[1, m]
        // f[0][j]: when p matches empty string 
        for (int j = 2; j <= n; j++) {
            if (p[j-1] == '*' && f[0][j-2])
                f[0][j] = true;
        }
        
        // i>0, j>0
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] != '*')
                    f[i][j] = f[i-1][j-1] && (s[i-1] == p[j-1] || '.' == p[j-1]);
                else
                    f[i][j] = f[i][j-2] || 
                            (f[i-1][j] && (s[i-1] == p[j-2] || '.' == p[j-2])); // NOTICE: check p[j-2] not p[j-1]
            }
        }
        return f[m][n];
    }
};
