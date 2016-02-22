class Solution {
    //dp[i] = max(dp[i-1], dp[i-1] + nums[i]);
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int maxLocal = 0;
        int maxGlobal = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxLocal += nums[i];
            maxGlobal = max(maxLocal, maxGlobal);
            maxLocal = max(0, maxLocal);
        }
        return maxGlobal;
        
    }
};