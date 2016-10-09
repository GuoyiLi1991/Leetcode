/////BFS? O(n)?
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int cnt = 0;
        int curMax = 0, nextMax = 0, i = 0;
        
        while (curMax >= i) { //when nodes count of current level > 0
            cnt++;
            while (curMax >= i) { //traverse current level, and update the max reach of next level
                nextMax = max(nextMax, nums[i] + i); //greedy
                if (nextMax >= n - 1) return cnt;
                i++;
            }
            
            if (curMax == nextMax) return INT_MAX; //cannot move forward from this level
            else curMax = nextMax;
        }
        
        return cnt;
    }
};
