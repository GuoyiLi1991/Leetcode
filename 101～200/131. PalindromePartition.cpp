//本质上是一个subset问题，valid cut的位置组合
class Solution {
    bool isPalindrome(string s, int i, int j) { //check if s[i, ....j] is a palindrome
        while (i <= j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    void dfs(vector<vector<string>>& res, vector<string>& group, string& s, int pos) {
        if (pos == s.size()) { // no more partition left
            res.push_back(group);
            return;
        }
        
        for (int i = pos; i < s.size(); i++) {
            if (isPalindrome(s, pos, i)) {
                group.push_back(s.substr(pos, i - pos + 1));
                dfs(res, group, s, i + 1);  // ****** i + 1!!! not pos+ 1
                group.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partition;
        dfs(res, partition, s, 0);
        return res;
    }
};

//改进：可以考虑preprocessing，来减小循环开销

