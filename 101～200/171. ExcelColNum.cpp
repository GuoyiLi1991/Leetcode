class Solution {
public:
    int titleToNumber(string s) {
        int map[26]= {0};
        for (int i = 0; i < 26; i++) {
            map[i] = i + 1;
        }
        int n = s.size();
        int res = map[s[0] - 'A'];

        for (int i = 1; i < n; i++) {
            res = res * 26 + map[s[i] - 'A'];
        }
        return res;
    }
};