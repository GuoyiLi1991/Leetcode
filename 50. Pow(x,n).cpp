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