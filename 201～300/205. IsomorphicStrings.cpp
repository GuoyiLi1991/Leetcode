// version 1: 2 maps recording the last location that
//              current char appeared ~10ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) 
            return false;
            
        int smap[256], tmap[256];
        for (int i = 0; i < 256; i++) {
            smap[i] = tmap[i] = -1;
        }
        
        for (int i = 0; i < m; ++i) {
            if (smap[s[i]] != tmap[t[i]])
                return false;
            smap[s[i]] = tmap[t[i]] = i;
        }
        return true;
        
    }
};

///// Another version, map s to t and t to s
// ~40ms
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m != n) 
            return false;
            
        unordered_map<char, char> m1;
        unordered_map<char, char> m2;
        
        for (int i = 0; i < m; i++) {
            if (!m1[s[i]]) m1[s[i]] = t[i];
            if (!m2[t[i]]) m2[t[i]] = s[i];
            if (m1[s[i]] != t[i] || m2[t[i]] != s[i])
                return false;
        }
        return true;
        
    }
};