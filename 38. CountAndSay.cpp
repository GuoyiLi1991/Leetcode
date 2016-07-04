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
