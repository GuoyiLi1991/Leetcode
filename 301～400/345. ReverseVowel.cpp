class Solution {
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string reverseVowels(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        int l = 0, r = n-1;
        while (l < r) {
            bool vl = isVowel(s[l]);
            bool vr = isVowel(s[r]);
            if (vl && vr) {
                swap(s[l++], s[r--]);
            }
            else if (vl) 
                r--;
            else l++;
        }
        return s;
    }
};