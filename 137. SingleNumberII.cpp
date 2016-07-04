class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < 32; ++i) {
            int sum = 0 ;
            for (int j = 0; j < nums.size(); j++) {
                sum += (nums[j] >> i) & 1;
            }
            
            if (sum % 3 != 0) {
                ans |= 1 << i;
            }
        }
        
        return ans;
    }
};