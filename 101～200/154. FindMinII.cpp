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

// another 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1 || nums[0] < nums[n - 1])//monotone increasing
            return nums[0];
        
        //general case
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) /2;
            if (nums[mid] < nums[mid - 1])
                return nums[mid];
            if (nums[mid] < nums[r]) //[l, pivot, mid, r], search [l, mid)
                r = mid - 1;
            else if (nums[mid] == nums[r])
                r--;
            else
                l = mid + 1;
                
        }
        return nums[l];
    }
};