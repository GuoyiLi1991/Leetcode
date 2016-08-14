class Solution {
    double helper(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x*x;
       // if (abs(x)<=0.5 && n>200000) return 0;
        if (n%2 == 0) return helper(helper(x,n/2),2);
            else return x * helper(helper(x,n/2),2);            
    }
public:
    double myPow(double x, int n) {
        if (n >=0) return helper(x,n);
        else return helper(1/x,-n);
    }

};


////////Combine them
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1/x;
            n = (n == INT_MIN)? INT_MAX - 1: -n;
        }
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;
        if (n % 2 == 0) //even power
            return myPow(x * x, n / 2);
        else //odd power
            return myPow(x * x, n / 2) * x;
        
    }
};