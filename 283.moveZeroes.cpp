// 对撞型双指针
// remember the end of original array
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return;
        
        int l =0, r = n-1;
        while (l<n && l<r)
        {
            if (nums[l] == 0)
            {
                nums.erase(nums.begin()+l);
                nums.push_back(0); 
                r--;
            }
            else ++l;
        }
    }
};

////////// 
// 快慢双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n) {
            if (nums[r]) {
                nums[l++] = nums[r];
            }
            r++;
        }
        while (l < n)
            nums[l++] = 0;
            
    }
};