class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n ==3) return nums[0]+nums[1]+nums[2];
        
        int delta = INT_MAX;
        int ret = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i<n-2; i++)
        {
            int l = i+1, r= n-1;
            while (l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if (sum ==target) return target;
                if (delta> abs(sum-target)) 
                {
                    delta = abs(sum-target);
                    ret = sum;
                }
                if (sum <target) l++;
                if (sum>target) r--;

            }
            while (nums[i] == nums[i+1])i++;
        }
        
        return ret;
        
    }
};