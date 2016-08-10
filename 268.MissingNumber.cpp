class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        
        //solution 1: sum them up
        for (int i = 0; i<n; i++)
        {
            result += i-nums[i];
        }
        return result+n;

        //solution 2: Bit maniputaion
        // int ans = 0;
        // for (int i = 0; i<n; i++)
        //     ans ^= nums[i] ^ i;
        // return ans^n;
        
    }
};
        
//solution 3: similar to 41.Finding missing positive
// swap nums[i] until nums[i] == nums[nums[i]]
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //vector<int> res(nums.size() + 1, -1);
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++) {
            while(nums[i] < n && nums[i] != nums[nums[i]] )
                swap(nums[i], nums[nums[i]]);
        }
        for (i = 0;i < n;i++){
            if (nums[i] != nums[nums[i]])
                break;
        }
        return i;
    }
};

// Solution 4: sum of all 0, 1,.... n  should be n*(n+1)/2
// The missing one appears after substracting all numbers from it
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int num:nums)
            sum -= num;
        return sum;
    }
};