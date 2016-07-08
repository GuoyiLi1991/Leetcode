class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res;
        if (n == 0) return res;
        if (n == 1) return strs[0];
        
        int len0 = strs[0].size(); //res can be at most this long
        for (int j = 0; j < len0; j++) { //iterate over str[0]
            char c = strs[0][j];
            for (int i = 0; i < n; i++) {
                int leni = strs[i].size();
                len0 = min(len0, leni);
                if (strs[i][j] == c)
                    continue;
                else 
                    return res;
            }
            res += c;
        }
        return res;
    }
};