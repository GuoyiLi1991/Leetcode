// transform(s.begin(), s.end(), s.begin(), ::tolower);

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n < 2) return true;
        int l = 0, r = n-1;
        while (l < r) {
            //first skipping non alphanumeric
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            // for digital
            if (isdigit(s[l]) && s[l] != s[r])
                return false;

            // for letters, ignore cases
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            
            l++;
            r--;
        }
        return true;
    }
};