class Solution {
    string hashing(string word) {
        //given a word, convert to a key for hashing
        string res;
        res += to_string(word.size());
        for (char c : word) {
            res += to_string((c - word[0] + 26) % 26);
        }
        return res;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> codebook;
        vector<vector<string>> res;
        int n = strings.size();
        if (n == 0) return res;
        
        for (string code : strings) {
            string key = hashing(code);
            codebook[key].push_back(code);
        }
        
        for (auto &item : codebook) {
            res.push_back(item.second);
        }
        
        return res;
    }
};