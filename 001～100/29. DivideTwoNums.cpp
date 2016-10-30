class Solution {
public:
    int divide(int dividend, int divisor) {
        //corner cases: easy or overflow
        if(divisor == 1) return dividend;
        if (divisor == 0) return INT_MAX;
        if(dividend == INT_MIN && abs(divisor) == 1)
            return INT_MAX;
        
        //general
        int sign = ((dividend ^ divisor) < 0) ? -1 : 1;

        long ans = 0;
        long a = abs((long)dividend);
        long b = abs((long)divisor);

        while(a >= b) { //called lgn times
            long term = b; // b * coef
            long coef = 1; //1, 10, 100, 1000, ....(binaries)
            
            while( (term << 1) < a) {
                coef <<= 1; //coef *= 2
                term <<= 1; //term = b * coef
            }
            
            ans += coef; //approach result using pow(2, i)
            a -= term;
        }
        return sign * ans;
    }
};