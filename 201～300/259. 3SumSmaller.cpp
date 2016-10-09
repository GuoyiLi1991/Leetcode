class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < n - 2; i++) {
            // if (nums[i] >= target)
            //     return cnt;
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum < target){
                    cnt += r - l;
                    l++;
                    
                }
                else r--;
            
            }
        }
        return cnt;
    }
};