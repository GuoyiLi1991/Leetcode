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