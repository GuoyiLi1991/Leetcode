class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size(); 
        if (s == t || m - n > 1 || n - m > 1)
            return false;
        
        if (m == 0 || n == 0)
            return true;
            
        if (m == n) { //only modification
            for (int i = 0; i < m; i++) {
                if (s[i] == t[i])
                    continue;
                else {
                    s[i] = t[i];
                    return s == t;
                }
            }
        }
        else {
            for (int i = 0; i < max(m, n); i++) {
                if (i < m && i < n && s[i] == t[i])
                    continue;
                else {
                    if (m < n) //t is longer
                        s.insert(s.begin() + i, t[i]);
                    else
                        t.insert(t.begin() + i, s[i]);
                    return s == t;
                }
            }
        }
        return false; //actually no need
    }
};


///////
// More consise
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s); //s is shorter
        
        if (s == t || n - m > 1)
            return false;
        for (int i = 0; i < m; i++) {
            if (s[i] == t[i])
                continue;
            //find the first difference
            if (m == n)
                return s.substr(i + 1) == t.substr(i + 1);
            else
                return s.substr(i) == t.substr(i + 1);
        }
        return true;
    }
};