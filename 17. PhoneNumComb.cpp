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

/////////////// My rewritten version /////////////////
class Solution {
    string map[10] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    void combination(vector<string> & res, string &str, string& digits, int pos) {
        if (str.size() == digits.size()) {
            res.push_back(str);
            return;
        }
        
        int num = digits[pos] - '0';
        string letters = map[num];
            
        for (int j = 0; j < letters.size(); j++) {
            str.push_back(letters[j]);
            combination(res, str, digits, pos + 1);
            str.pop_back();
         }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0 || digits.find('1') != string::npos || digits.find('0') != string::npos) //contains 0 or 1
            return res;
        string str;

        combination(res, str, digits, 0);
        return res;
    }
};

////////////////
// Non-recursive way, just loop
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n = digits.size();
        if (n == 0) return res;
        
        //general cases
        res.push_back("");
        string dig_letter[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < n; i++) { //for every digit
            for (int j = res.size() - 1; j >= 0; j--) {
                int d = int(digits[i] - '0');
                string str = dig_letter[d];
                for (int k = 0; k < str.size(); k++) { //for each possible letter represented by number d
                    if (k != str.size() - 1)
                        res.push_back(res[j] + str[k]);
                    else
                        res[j] += str[k];
                }
            }
        }
        
        return res;
    }
};