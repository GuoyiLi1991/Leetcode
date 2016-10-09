//exactly two elements appear only once, others appear exactly twice
//divide into two groups by the rightmost different digit
// d = d & (~(d-1));
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2,0);
        int d = 0;
        
        for (int i = 0; i< n; i++)
        {
            d ^= nums[i];
        }
        
        d = d & (~(d-1)); // get the rightmost different digit
        
        for (int i = 0; i<n; i++)
        {
            if ((d & nums[i]) == d) //cur dig = 0
                ans[0] ^= nums[i];
            else 
                ans[1] ^= nums[i];
        }
        
        return ans;
        
    }
};