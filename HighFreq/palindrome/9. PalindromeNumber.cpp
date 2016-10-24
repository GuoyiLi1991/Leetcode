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

////////////// Without Extra Space //////////////////
/* Pay attention to double pow(double base, double power); */
class Solution {
public:
    bool isPalindrome(int x) {
         if (x < 0 || x >= INT_MAX)
             return false;
            
        int n = 0; // number of digits
        int v = x;
        while (v) {
            n++;
            v /=10;
        }
        //cout << n;
        
        v = x;
        while (n > 1) {
            if (v/int(pow(10, n-1)) != v % 10)
                return false;
            v = (v/10) % int(pow(10, n-2));
            n -= 2;
        }
        return true;
    }
};