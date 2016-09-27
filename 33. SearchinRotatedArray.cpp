////////
// Sol1: One pass
// Time: O(n), space: O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};

/////////////////////
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) 
            return (nums[0] == target)? 0 : -1;
        
        int l = 0, r = n - 1;
        //find pivot: index of smallest element
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] > nums[r]) //search right half
                l = mid + 1;
            else
                r = mid;
        }//stops when l == r
        int k = r;  //given num[i] in sorted array, now its value is at num[(i+k)%n]
        
        //search for target
        l = 0;
        r = n - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            int shifted = (mid + k) % n;
            if (nums[shifted] == target)
                return shifted;
            if (nums[shifted] < target) //search right half
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return -1;
    }
};

///////////////////

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


/////////////////
// http://fisherlei.blogspot.com/2013/01/leetcode-search-in-rotated-sorted-array.html
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == target) 
                return mid;
            if (nums[mid] >= nums[l]) {
                if (nums[l] <= target && target <= nums[mid]) //search within [l, mid)
                    r = mid - 1;
                else // search within (mid, r)
                    l = mid + 1;
            }
            else {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};

