class Solution {
    void dfs(vector<string>& res, string cur, string word, int pos) {
        if (pos == word.size()) {
            res.push_back(cur);
            return;
        }
        
        int i = pos;
        
        dfs(res, cur + word[i], word, i + 1);
        for (i = pos + 1; i < word.size(); i++) {
            dfs(res, cur + to_string(i - pos) + word[i], word, i + 1);
        }
        dfs(res, cur + to_string(i - pos), word, i);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        dfs(res, "", word, 0);
        return res;
    }
};

// My solution:
// generate 2^n kinds of mask of 0000, 0001, ~1111
// replace the original string by '1' if the mask digit is 1
class Solution {
    string brief(string word) {
        //given '111d', return '3d'
        string res;
        int cnt = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '1')
                cnt++;
            else {
                if (cnt != 0) {
                    res += to_string(cnt);
                }
                res += word[i];
                cnt = 0;
            }
        }
        if (cnt != 0) 
            res += to_string(cnt);
        return res;
    }
    
    void replace(vector<string>& res, string word) {
        int n = word.size();
        for (int i = 0; i < pow(2, n); i++) {
            string output = word;
            for (int j = 0; j < word.size(); j++) {
                if ((i >> j) & 1) //i is the mask
                    output[j] = '1';
            }
            res.push_back(brief(output));
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        int pos = 0;
        replace(res, word);
        return res;
    }
};
