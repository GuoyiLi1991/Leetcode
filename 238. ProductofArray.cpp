class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        // from left to right
        int dummy = 1;
        for (int i = 1; i < n; ++i) {
            dummy *= nums[i-1];
            res[i] = dummy;
        }
        
        // from right to left
        dummy  = 1;
        for (int i = n - 2; i >=0; --i) {
            dummy *= nums[i + 1];
            res[i] *= dummy;
        }
        return res;
        
    }
};