// Sol1: res *= x for n times
// Time: O(n)
class Solution {
    double helper(double x, int n) { //when n >= 0
        if (x == 0 || x == 1) return x;
        if (x == -1) return (n % 2 == 0)? 1 : -1;
        
        double res = 1;
        while (n--) {
            res *= x;
            if (res == 0) break;
        }
            
        return res;
    }
public:
    double myPow(double x, int n) {
        if (n >= 0) return helper(x, n);
        else return helper(1/x, -n);
    }
};


// Sol2. Binary power Recursive
// Time: O(log n)
class Solution {
    double helper(double x, int n) { //when n >= 0
        //corner cases:
        if (x == 0 || x == 1) return x;
        if (x == -1) return (n % 2 == 0)? 1 : -1;
        
        //base case:
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == 2) return x * x;
        
        // divide and conquer
        if (n % 2 == 0) 
            return helper(helper(x, n/2), 2);
        else
            return helper(helper(x, n/2), 2) * x;
    }
public:
    double myPow(double x, int n) {
        if (n >= 0) return helper(x, n);
        else return helper(1/x, -n);
    }
};

// Sol3. Binary Iterative
class Solution {
    double helper(double x, int n) { //when n >= 0
        //corner cases:
        if (x == 0 || x == 1) return x;
        if (x == -1) return (n % 2 == 0)? 1 : -1;
        
        //base case:
        if (n == 0) return 1;
        double res = 1;
        while (n != 0) {
            if ((n & 1) != 0)
                res *= x;
            x *= x;  //x^2, x^4, x^8, x^16, ...
            n >>= 1;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) return helper(1/x, INT_MAX - 1);
        if (n >= 0) return helper(x, n);
        else return helper(1/x, -n);
    }
};