class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        if (n == 3 || n == 4) return 2;
        if (n >= pow(2, 31) - 1) return 32;
        if (n % 2) //odd
            return 2 + min(integerReplacement(n / 2), integerReplacement((n + 1)/2) );
        else
            return 1 + integerReplacement(n / 2);
    }
};