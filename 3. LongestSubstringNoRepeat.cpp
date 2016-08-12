class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
        vector<int> ht(256, -1);
        int start = -1;
        //find all break points for repeations
        for (int i = 0; i < s.size(); i++) {
            int c = s[i];
            if (ht[c] > start) //update start to the start of current interval
                start = ht[c];
            ht[c] = i;
            len = max(len, i - start);
        }
        
        return len;
        
    }
};