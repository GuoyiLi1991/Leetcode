class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size()<2) return; 
       // sort(nums.begin(), nums.end());
        for (int i = 1; i<nums.size(); i = i+2)
        {
            if (nums[i-1] > nums[i])
                swap(nums[i-1], nums[i]);
            if (i+1<nums.size() && nums[i+1]>nums[i])
                swap(nums[i+1], nums[i]);
        }
        
    }
};