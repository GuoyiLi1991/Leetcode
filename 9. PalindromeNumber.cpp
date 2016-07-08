class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.size();
        
        for (int i = 0; i < n/2; i++) {
            if (s[n-1-i] != s[i])
                return false;
        }

        /* or use two pointers 
        int l = 0, r = n-1;
        while (l < r) {
			if (s[l++] != s[r--])
				return false;
        }
    	*/ 
    	
        return true;
    }
};