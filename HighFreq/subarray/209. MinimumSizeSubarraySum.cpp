class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(); 
        if (n == 0) return 0;
        
        int l = 0;
        int res = n + 1; 
        int cur_sum = 0;
        for (int r = 0; r < n; r++) {
            cur_sum += nums[r];
            while (cur_sum >= s) {
                res = min(res, r - l + 1);
                cur_sum -= nums[l];
                l++;
            }
        }
        
        return (res == n + 1)? 0 : res;

    }
};

