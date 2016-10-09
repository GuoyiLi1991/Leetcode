class Solution {
private:
    int lo, maxLength;
    void extendPalindrome(string s, int low, int high) //find maximum length and starting point
    {
        while (low >= 0 && high < s.length() && s[low] == s[high])
        {
            low--;
            high++;
        }
        
       low++;high--;
        
        if (maxLength < high-low+1) //max < current
        {
            lo = low; //save current starting point
            maxLength = high-low+1; //update maxLength
        }
    }
public:
    string longestPalindrome(string s) {
        int length=s.length();
        if (length<2) return s;
        
        //length >=2, find palindrome after ith char
        for (int i=0; i<length; i++)
        {
            extendPalindrome(s, i, i); //assume odd length palindrome
            extendPalindrome(s, i, i+1); //assume even length palindrom
        }
       // cout<<maxLength;
        return s.substr(lo, maxLength);
        
    }
    
};



////////////
// for each c in s, find longest palindrome with two pointers
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        
        int maxLen = 0;
        int start = 0;
        
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (r < n && s[r] == s[r+1])
                r++;
            while (l > 0 && r < n - 1 && s[l - 1] == s[r + 1]) { 
                // 1) l and r are legal 
                // 2) palindrome is extensible 
                l--;
                r++;
            }
            
            int len = r - l + 1;
            if (len > maxLen) {// found a better sol
                maxLen = len;
                start = l;
            }
        }
        
        return s.substr(start, maxLen);
            
    }
};
