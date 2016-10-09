class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        
        if (m < n) return -1;
        if (m == n)
            return (haystack == needle)? 0:-1;
        
        // m > n
        for (int l = 0; l <= m-n; l++)
        {
            int i = 0;
            while (i < n && haystack[l+i] == needle[i])
                i++;
            
            if ( i == n) //found
                return l;
        }
        
        return -1;
        
    }
};


///////////////////////////
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (m < n) 
            return -1;
        if (n == 0)
            return 0;
            
        int res = -1;
        int l = 0, r = 0; //two pointers in haystack
        int p = 0;
        while (r < m && p < n) {
            if (haystack[r] == needle[p]) {
                r++; p++;
            }
            else {
                l++;
                r = l;
                p = 0;
            }
        }
        
        if (p == n) return l;
        else return -1;
        
    }
};

////////////////////
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n > m) return -1;
        if (n == 0 || haystack == needle) return 0;
        
        int l = 0, r = 0;
        while (r < m && r - l < n) {
            if (haystack[r] == needle[r - l])
                r++;
            else
                r = ++l;
        }
        
        if (r - l == n) return l;
        else return -1;
    }
};