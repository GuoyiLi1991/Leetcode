class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i+1; j < n-2; j++)
            {
                int l = j + 1, r = n-1;
                while (l < r)
                {
                    int sum = nums[i] + nums[j] + nums [l] + nums[r];
                    if (sum == target)
                    {
                        //save to res
                        vector<int> quad{nums[i], nums[j], nums[l], nums[r]};
                        res.push_back(quad);
                        //avoid duplication
                        while (l < r && nums[l] == nums[l+1]) l++;
                        while (l < r && nums[r] == nums[r-1]) r--;
                        //move on
                        l++;
                        r--;
                    }
                    else if (sum > target)
                        r--;
                    else 
                        l++;
                }
                while (nums[j] == nums[j+1]) j++;
            }
            while (nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};