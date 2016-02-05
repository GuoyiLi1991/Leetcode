// transform(s.begin(), s.end(), s.begin(), ::tolower);

class Solution {
public:
    bool isPalindrome(string s) {
        //corner cases
        if (s.length() <2)
            return true;
            
        transform(s.begin(), s.end(), s.begin(), ::tolower);
            
        //check with 2 pointers
        int l =0, r = s.length()-1;
        while (l<=r)
        {
            //skip non-alphanumeric chars
            while (!isalnum(s[l]) && l<r) l++;
            while (!isalnum(s[r]) && l<r) r--;
            
            if (l==r) return true;
            
            if (s[l] != s[r]) return false;
            else 
            {
                l++;
                r--;
            }
        }
        return true;
    }
};