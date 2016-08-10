//swap each number num to nums[num - 1]

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 1;
        int i;
        for (i  = 0; i < n; i++) {
            while (nums[i] > 0  && nums[i] -1 < n && nums[i] != nums[nums[i] - 1])  //NOTICE: "while" instead of "if"
                swap(nums[i], nums[nums[i] - 1]);
        }
        
        
        for (i = 0; i < n; i++) {
            //cout << nums[i] <<endl;
            if (nums[i] != i + 1)
                break;
        }
        
        return (i + 1);
    }
};
