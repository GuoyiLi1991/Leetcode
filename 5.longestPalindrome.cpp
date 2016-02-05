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
