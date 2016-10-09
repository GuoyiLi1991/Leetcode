class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) 
            return n;
            
        vector<int> res{nums[0]};

        int i = 1;
        while (i < n) {
            if (nums[i] == res[res.size()-1]) {
                res.push_back(nums[i]);
                while (i < n && nums[i] == nums[i-1])
                        i++;
            }
            else {
                res.push_back(nums[i++]);
            }
        }
        nums.clear();
        nums = res;
        return res.size();
    }
};
////////////////////////////////////
// In place
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) 
            return n;
            
        int slow = 0, fast = 1;
        bool dup = false;
        while (fast < n) {
            if (nums[slow] == nums[fast]) {
                if (!dup) {
                    nums[++slow] = nums[fast];
                    dup = true;
                }
            }
            else {
                nums[++slow] = nums[fast];
                dup = false;
            }
            fast++;
        }
        return slow+1;
    }
};

//////////////////////