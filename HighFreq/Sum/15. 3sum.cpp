class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3) return res;
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back(vector<int>({nums[i], nums[l], nums[r]}));
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    while (i < n - 2 && nums[i] == nums[i + 1])
                        i++;
                    l++; r--;
                        
                }
                else if (sum < 0) {
                    l++;
                }
                else r--;
            }
            
        }
        return res;
    }
};