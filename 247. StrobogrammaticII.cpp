/* A strobogrammatic number is a number that looks the 
same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

*/
class Solution {
    void dfs(vector<string>& res, string s, int n, vector<pair<char, char>>& ht) {
        if (s.size() == n) {
            if (s[0] != '0') 
                res.push_back(s);
            return;
        }    
        for (int i = 0; i < ht.size(); i++) {
            pair<char, char> tmp = ht[i];
            s = tmp.first + s + tmp.second;
            dfs(res, s, n, ht);
            s = s.substr(1, s.size() - 2);
        }
    }
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        vector<pair<char, char>> ht = {{'1','1'}, {'8','8'}, {'6','9'},{'9','6'}, {'0','0'}};
        if (n % 2) {
            dfs(res, "0", n, ht);
            dfs(res, "1", n, ht);
            dfs(res, "8", n, ht);
        }
        else dfs(res, "", n, ht);
        
        if (n == 1) res.push_back("0");
        return res;

    }
};

////////////////////////
class Solution {
    vector<string> helper(int m, int n) {
        if (m == 0) return vector<string>({""});
        if (m == 1) return vector<string>({"0", "1", "8"});
        
        vector<string> res;
        vector<string> tmp = helper(m - 2, n);
        for (int i = 0; i < tmp.size(); i++) {  //extend string of length m-2
            string cur = tmp[i];
            if (m != n) 
                res.push_back("0" + cur + "0");
            res.push_back("1" + cur + "1");
            res.push_back("6" + cur + "9");
            res.push_back("9" + cur + "6");
            res.push_back("8" + cur + "8");
        }
        return res;
    }
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n, n);

    }
};