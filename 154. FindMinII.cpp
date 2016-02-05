class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r=nums.size()-1;
        while (l<r)
        {
            while(nums[l] == nums[l+1]) l++;   //added
            int mid = (l+r)/2;
            nums[mid] > nums[r]?l = mid+1:r = mid;
        }
        return nums[r];
        
    }
};