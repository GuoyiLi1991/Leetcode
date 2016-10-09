///// Recursive
class Solution {
public:
    string reverseString(string s) {
        int n = s.size();
        if (n < 2) return s;
        return reverseString(s.substr(n/2)) + reverseString(s.substr(0, n/2));
    }
};


////// Iterative
class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        if (n < 2)
            return s;
        string res(s);
        int l = 0, r = n - 1;
        while (l < r) 
            swap(res[l++], res[r--]);
        return res;
    }
};