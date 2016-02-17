class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        //solution 1: sum them up
        for (int i = 0; i<n; i++)
        {
            result += i-nums[i];
        }
        return result+n;

        //solution 2: Bit maniputaion
        // int ans = 0;
        // for (int i = 0; i<n; i++)
        //     ans ^= nums[i] ^ i;
        // return ans^n;
        
    }
};
        