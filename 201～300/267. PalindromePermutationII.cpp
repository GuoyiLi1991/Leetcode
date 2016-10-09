///////// Workable, but TLE for the last test case
class Solution {
    bool isPalind(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void permutation(vector<string> &res, string cur, string s, vector<bool>& visited) {
        if (cur.size() == s.size()){
            if (isPalind(cur))
                res.push_back(cur);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                cur += s[i];
                permutation(res, cur, s, visited);
                cur = cur.substr(0, cur.size() - 1);
                visited[i] = false;
                //deal with duplication
                while (i < s.size() && s[i] == s[i + 1])
                    i++;
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        
        if (s.size() > 10) return res;
        vector<bool> visited(s.size(), false);
        
        sort(s.begin(), s.end());
        permutation(res, "", s, visited);
        return res;
    }
};

/////////////////////
// Faster Sol
class Solution {
    void permutation(vector<string> &res, string cur, string s, string extra, vector<bool>& visited) {
        if (cur.size() == s.size() * 2){
           if (extra.size() == 1)
                cur.insert(s.size(), extra);
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            if (visited[i] == false) {
                visited[i] = true;
                cur = s[i] + cur + s[i];
                permutation(res, cur, s, extra, visited);
                cur = cur.substr(1, cur.size() - 2);
                visited[i] = false;
                //deal with duplication
                while (i < s.size() && s[i] == s[i + 1])
                    i++;
            }
        }
    }
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        if (s.size() == 0) return res;
        if (s.size() == 1)
            return vector<string>{s};
        
        int ht[256]; //count frequencies
        fill_n(ht, 256, 0);
        
        for (char c:s)
            ht[c]++;
            
        string single;
        string even; // even chars
        for (int i = 0; i < 256; i++) {
            int j = ht[i] / 2;
            if (ht[i]  != j * 2) {
                single += char(i);
                if (single.size() > 1){
                    cout <<"single";
                    return res;
                }
                    
            }
            while (j--)
                even += char(i);
        }

        vector<bool> visited(even.size(), false);
        permutation(res, "", even, single, visited );

        return res;
    }
};
