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