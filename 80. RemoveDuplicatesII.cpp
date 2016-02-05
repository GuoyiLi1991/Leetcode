class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n ==0) return 0;
        
        int len = 0, cnt = 0;
        for (int i = 1; i< n; i++)
        {
            if (nums[len] == nums[i] )
            {
                cnt++;  // num of repetion
                if (cnt <2)
                    nums[++len] = nums[i];
            }
            else 
            {
                nums[++len] = nums[i];
                cnt = 0;
            }
        }
        return len+1;
    }
};