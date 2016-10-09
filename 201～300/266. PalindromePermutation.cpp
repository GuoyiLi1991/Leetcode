class Solution {
public:
    bool canPermutePalindrome(string s) {
        int ht[256];
        fill_n(ht, 256, 0);
        
        for (char c:s) {
            if (ht[c] == 1)
                ht[c]--;
            else
                ht[c]++;
        }
        
        int flag = false;
        for (int i = 0; i < 256; i++) {
            if (ht[i] == 1)
                if (!flag)
                    flag = true;
                else
                    return false;
        }
        
        return true;
    }
};