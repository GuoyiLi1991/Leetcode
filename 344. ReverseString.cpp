class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
        if (n < 2)
            return s;
        // for (int i = 0; i < n/2; i++) {
        //     swap(s[i], s[n-1-i]);
        // }
        // return s;
        return reverseString(s.substr(n/2))+reverseString(s.substr(0, n/2));
    }
};