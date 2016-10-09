class Solution {
public:
    int firstUniqChar(string s) {
        int ht[256];
        fill_n(ht, 256, 0);
        for (char c : s) {
            ht[c]++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (ht[s[i]] == 1) {
                return i; 
            }
        }
        return -1;
    }
};