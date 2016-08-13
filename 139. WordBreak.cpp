class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        //DP
        bool isValid[n + 1]; // isValid[i] is true if s[0...i) can be segmented with words in dictionary
        fill_n(isValid, n + 1, false);
        isValid[0] = true;
    
        for (int end = 0; end < n; end++)  // any i in s[0, ... n-1]
            for (int begin = 0; begin <= end; begin++) { //exhaust previous workable solution
                bool until = isValid[begin];
                string rest = s.substr(begin, end - begin + 1);
                if (until && wordDict.find(rest) != wordDict.end()) {
                    isValid[end + 1] = true;
                    break;
                }
            }
        return isValid[n];
    }
};