class Solution {
public:
    int findMin(vector<int>& nums) {
        /*************O(n)****************/
        int n = nums.size();
        if (n ==1) return nums[0];
        
        int i = 0;
        while(nums[i]<nums[i+1] && i<n-1) i++;
        
        if (i==n-1) return nums[0];//all sorted
        return nums[i+1];
        
        /***********Binary Search O(logn)**********/
    //     int n = nums.size();
    //     if (n==1) return nums[0];
        
    //     int l = 0, r=n-1;
    //     while (l<r-1)
    //     {
    //         if (nums[l] < nums[r]) //all sorted
    //             return nums[l];
                
    //         int mid = (l+r)/2;
    //         if (nums[l]<nums[mid])//left part is sorted
    //             l = mid;
    //         else
    //             r = mid;
    //     }
    //     return min(nums[l], nums[r]);

        /**********Shorter BS******************/
        int l = 0, r=nums.size()-1;
        while (l<r)
        {
            int mid = (l+r)/2;
            nums[mid] > nums[r]?l = mid+1:r = mid;
        }
        return nums[r];
        /**************************************/
     }
};