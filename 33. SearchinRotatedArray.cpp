class Solution {
    int BinarySearch(vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (nums[mid] == target)
                return mid;
            nums[mid] < target? l = mid+1: r = mid-1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // if (n == 0) return -1;
        // if (n == 1) return (target == nums[0])-1;
        
        //find pivot
        int pivot = -1;
        int l = 0, r = n-1;
        while (l < r)
        {
            int mid = l + (r-l)/2;
            nums[mid] > nums[r]? l = mid+1: r = mid;
        }
        pivot = r-1; //index of maximum
        cout <<pivot;
        if (pivot == -1) //all ascending
            return BinarySearch(nums, 0, n-1, target);
        // if (target > nums[pivot] || target < nums[r] || (target >nums[n-1] && target < nums[0]))
        //     return -1;
        else if (target >=nums[0])
            return BinarySearch(nums, 0, pivot, target);
        else
            return BinarySearch(nums, pivot+1, n-1, target);
    
    }
};