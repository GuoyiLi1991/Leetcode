///////////////
// Sol 1: One pass O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
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

/////////
// Sol 2-1: Binary Search O(lg n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {        
        int n = nums.size();
        if (n < 2 || nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return (n - 1);
        
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            if (nums[mid] < nums[mid + 1]) //search right half
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};

//////////
// Sol 2-2 : kind of binary search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n-1;
        while (l<r)
        {
            int mid = l+(r-l)/2;
            if (nums[mid] > nums[mid+1]) //search left half
                r = mid;
            else l = mid+1;
        }
        return l;
    }
};