class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int n = nums.size();
        
        // int l = 0, r = n-1;

        // while (l<r)
        // {
        //     int mid = l+(r-l)/2;
        //     if (nums[mid] > nums[mid+1]) //search left half
        //         r = mid;
        //     else l = mid+1;
        // }
        // return l;
        
        if (nums.size() == 1 || nums[0]>nums[1]) return 0;
        
        int i;
        for (i = 1; i< nums.size()-1; i++)
        {
            if (nums[i] > nums[i-1] && nums[i]>nums[i+1])
                return i;
        }
        return i;
        
    }
};