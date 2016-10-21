/* 

针对全负数数列，要问清楚要求：
    1. 如果假设subarray不为空， maxSum初始化为nums[0]
    2. 如果假设subarray可以为空，maxSum初始化为0
    3. 如果假设sum必须非负，maxSum初始化为INT_MIN???

*/

class Solution {
    //dp[i] = max(nums[i], dp[i-1] + nums[i]);
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int runningSum = 0;
        int maxSum = INT_MIN; // or nums[0]
        for (int i = 0; i < n; i++)
        {
            runningSum += nums[i];
            maxSum = max(maxSum, runnignSum);
            if (runningSum < 0) //won't help increasing the rest
               runningSum = 0;
        }
        
        return maxSum;
    }
};

// Sol2. DP, O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int runningSum = nums[0]; 
        int maxSum = nums[0]; //at least include one number
        for (int i = 1; i < n; i++) {
            runningSum = max(nums[i], runningSum + nums[i]); 
            //either start all over, or contribute to the previous
            maxSum = max(maxSum, runningSum);
        }
        
        return maxSum;
        
    }
};



///// Further: print the idx of subarray (start, end)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int runningSum = nums[0]; 
        int maxSum = nums[0]; //at least include one number
        int maxStartIdx = 0;
        int maxEndIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > runningSum + nums[i]) {
                runningSum = nums[i];
                maxStartIdx = i; //update start
            }
            else
                runningSum += nums[i];
                
            if (runningSum > maxSum) {
                maxSum = runningSum; //update end
                maxEndIdx = i;
            }
           
        }
        
        cout << "(" << maxStartIdx << "," << maxEndIdx  << ")" <<endl;
        return maxSum;
        
    }
};