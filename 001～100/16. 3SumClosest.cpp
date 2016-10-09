class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0, dist = INT_MAX;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 1; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == target)
                    return target;
                if (sum > target) r--;
                if (sum < target) l++;
                
                if (abs(sum-target) < dist) { //found a better/closer sol
                    dist = abs(sum-target);
                    res = sum;
                }
            }
        }
        return res;
    }
};