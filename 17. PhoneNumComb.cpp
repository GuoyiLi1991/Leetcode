class Solution {
    void dfs(vector<string>&ret, string s, const string &digits, unordered_map<char, string> ht, int pos)
    {
        if (digits.size() == 0 || digits.size() == s.size())
        {
            ret.push_back(s);
            return;
        }
        
        char key =  digits[pos];
        string charset =  ht[key];
        for (int i = 0; i<charset.size(); i++)
        {
            s += charset[i];
            dfs(ret, s, digits, ht, pos+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int n = digits.size();
        if (n == 0) return ret;
        
        unordered_map<char, string> ht = {
            {'2',"abc"}, {'3', "def"}, 
            {'4', "ghi"}, {'5', "jkl"}, {'6',"mno"},
            {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
            
        dfs(ret, "", digits, ht, 0);
        return ret;
    }
};

// could be faster if change unordered_map to ht[10]
class Solution {
   // void dfs(vector<string>&ret, string s, const string &digits, unordered_map<char, string> ht, int pos)
    void dfs(vector<string>&ret, string s, const string &digits, string ht[], int pos)
    {
        if (digits.size() == 0 || digits.size() == s.size())
        {
            ret.push_back(s);
            return;
        }
        
        char key =  digits[pos];
        string charset =  ht[key-'0'];
        for (int i = 0; i<charset.size(); i++)
        {
            s += charset[i];
            dfs(ret, s, digits, ht, pos+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int n = digits.size();
        if (n == 0) return ret;
        
        string ht[10] = {"", "", "abc","def","ghi",
                    "jkl","mno","pqrs","tuv","wxyz"};
            
        dfs(ret, "", digits, ht, 0);
        return ret;
    }
};