class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        // from left to right
        int front_so_far = 1;
        int back_so_far = 1;
        for (int i = 1; i < n; ++i) {
            front_so_far *= nums[i - 1];
            res[i] = front_so_far;
        }
        
        // from right to left
        for (int i = n - 2; i >=0; --i) {
            back_so_far *= nums[i + 1];
            res[i] *= back_so_far;
        }
        
        return res;
    }
};