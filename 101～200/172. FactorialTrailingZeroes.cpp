//Sol1.Recursion
class Solution {
public:
    int trailingZeroes(int n) {
        return (n == 0)? 0: n / 5 + trailingZeroes(n/5);
    }
};

// Sol2: Iterative
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        if (n <= 0)
            return 0;
            
        for (long i = 5; n / i > 0; i *= 5) {
            cnt += n / i;
        }
        return cnt;
    }
};


/* 

cnt += #of multiple of 5
	   += #of multiple of 25
	   += #of multiple of 125
	   += ...

*/