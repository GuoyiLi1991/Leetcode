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
                if (p[j-1] == '?')  //ignoring checking the cur char, totally depends on the history
                    f[i][j] = f[i-1][j-1];
                else if (p[j-1] == '*')  
                //true either 1)already matches s completely, but with trailing stars 2)"*" can deal with all the rest
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


////////// Someone else's solutions
// Analysis: https://discuss.leetcode.com/topic/21577/my-three-c-solutions-iterative-16ms-dp-180ms-modified-recursion-88ms/2
////////// DP with trick
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int cur, prev;
        if (!n) return !m;
        // vector<vector<bool>> matched(2, vector<bool>(m + 1, false)); // 1400ms
        bool matched[2][m+1];  //192ms
        fill_n(&matched[0][0], 2 * (m+1), false);
        
        matched[0][0] = true; //both are empty
        for (int i = 1; i <= n; i++) {
            cur = i % 2, prev = 1 - cur;
            matched[cur][0] = matched[prev][0] && p[i-1] == '*';
            if (p[i-1] == '*')
                for (int j = 1; j <= m; j++)
                    matched[cur][j] = matched[cur][j-1] || matched[prev][j];
            else 
                for (int j = 1; j <= m; j++)
                    matched[cur][j] = matched[prev][j-1] && (p[i-1] == '?' || p[i-1] == s[j-1]);
        }
        
        return matched[cur][m];
    }
};

/////// DFS recursion: 88ms
class Solution {
private:
    bool helper(const string &s, const string &p, int si, int pi, int &recLevel)
    {
        int m = s.size(), n = p.size();
        int curLevel = recLevel;

        bool first=true;
        while(si < m && (p[pi]==s[si] || p[pi]=='?')) {++pi; ++si;} //match as many as possible
        if(pi == n) return si == m; // if p reaches the end, return
        
        if(p[pi]=='*') { // if a star is met
            while (p[++pi] == '*'); //skip all the following stars
            if(pi >= n) return true; // if the rest of p are all star, return true
            
            for(int i = si; i<m; ++i)
            {   // then do recursion
                if(p[pi]!= '?' && p[pi]!=s[i]) continue;
                if(first) {
                    ++recLevel; 
                    first = false;
                }
                
                if(helper(s, p, i, pi, recLevel)) return true;
                if(recLevel>curLevel+1) return false; // if the currently processed star is not the last one, return
            }
            
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        int recLevel = 0;
        return helper(s, p, 0, 0, recLevel);
    }
};


