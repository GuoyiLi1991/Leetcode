// Sol1. BruteForce
// O(max(m, n))
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        if (m == 0) return true;
        if (m > n) return false;
        
        int i = 0, j = 0; //pointers in s and t
        while (i < m && j < n) {
            if (s[i] == t[j])
                i++;
            j++;
        }
        return (i == m);
    }
};