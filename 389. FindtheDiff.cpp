///// Sol1. HashTable
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hts[26];
        fill_n(hts, 26, 0);
        for (char c:s) 
            hts[c - 'a']++;
        for (char c:t) {
            if (hts[c - 'a'])
                hts[c - 'a']--;
            else
                return c;
        }
        return t[0];
    }
};

///// Sol2. Bit manipulation
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res ^= s[i];
            res ^= t[i];
        }
        return res ^ t[n];
    }
};