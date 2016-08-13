class Solution {
public:
    bool canJump(vector<int>& nums) {
        //int pos = 0;
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (reachable < i) return false; //last action is 0
            reachable = max(reachable, i + nums[i]);
            if (reachable >= nums.size() - 1) return true;
        }
        return false;
    }
};