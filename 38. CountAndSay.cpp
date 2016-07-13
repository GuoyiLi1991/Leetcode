class Solution {
public:
    string countAndSay(int n) {
        if (n==0) return "";
        string res = "1"; //n = 1;
        
        for (int idx = 1; idx< n; idx++)
        {
            string cur = "";
            for (int i = 0; i<res.size(); i++)
            {
                int cnt = 1;
                while ((i<res.size()-1) && (res[i] == res[i+1]))
                {
                    cnt++;
                    i++;
                }
                cur += to_string(cnt) + res[i];
            }
            res = cur;
        }
        return res;
    }
};

/////////////////////////////
class Solution {
    string next(string s) { //tells the next string of s
        string res;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            char cur = s[i];
            if (cur == c) {
                cnt++;
                continue;
            }
            else {
                res += to_string(cnt) + c;
                c = cur;
                cnt = 1;
            }
        }
        res += to_string(cnt) + c;
        return res;
    }
public:
    string countAndSay(int n) {
        string res;
        if (n == 1)
            return "1";
        
        string s = "1";
        for (int i = 2; i <= n; i++) {
            s = next(s);
        }
        return s;
    }
};
