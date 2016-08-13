class Solution {
    // void backtracking(int & result, vector<int> opt, int target) {  //TLE
    //     if (target == 0) {
    //         result++;
    //         return;
    //     }
        
    //     if (target < 0) 
    //         return;
            
    //     for (int i = 0; i < opt.size(); i++) {
    //         target -= opt[i];
    //         backtracking(result, opt, target);
    //         target += opt[i];
    //     }
    // }
public:
    int climbStairs(int n) {   
        // int res; //Backtracking has TLE
        // vector<int> opt{1,2};
        // backtracking(res, opt, n);
        // return res;
        
        //////////////////////////
        // Fibonacci numbers /////  // O(1)space, O(n) time
        int res;
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int x_two_before = 1;
        int x_one_before = 2;
        
        for (int i  = 2; i < n; i++) {
            res = x_two_before + x_one_before;
            x_two_before = x_one_before;
            x_one_before = res;
        }
        return res;
            
    }
};

///// Standard dp: O(n) space, O(n) time
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) return 0;
        int dp[n]{0};
        dp[0] = 1; //n = 1;
        dp[1] = 2; //n = 2
        for (int i = 2; i < n; i++) 
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n - 1];
    }
};