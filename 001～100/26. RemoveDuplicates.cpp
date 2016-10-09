class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int len = 0;
        for (int i = 1; i<n; i++)
        {
            if (nums[len] != nums[i])
            {
                nums[++len]  = nums[i];
            }
        }
        return len+1;
    }
};


////////////////////
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return n;
        int l = 1, r = 1;
        while (r < n) {
            if (nums[r] != nums[r-1]) {
                nums[l++] = nums[r++];
            }
            else r++;
        }
        return l;
    }
};