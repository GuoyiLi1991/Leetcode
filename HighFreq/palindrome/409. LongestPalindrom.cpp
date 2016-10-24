class Solution {
public:
    int longestPalindrome(string s) {
        int freq[52];
        fill_n(freq, 52, 0);
        
        for (char c : s) {
            if (!isalpha(c)) continue;
            if (isupper(c))freq[c - 'A']++;
            if (islower(c))freq[c - 'a' + 26]++;
        }
        
        int res = 0;
        bool has_odd = false;
        for (int i = 0; i < 52; i++) {
            if (freq[i] != 0) 
            if (freq[i] % 2 == 0)
                res += freq[i];
            else {
                res += freq[i] - 1; //Attention!!!
                has_odd = true;
            }          
        }
        
        return res + has_odd;
    }
};