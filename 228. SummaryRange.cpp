class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        if (n == 0) return ret;
        if (n == 1) 
        {
            ret.push_back(to_string(nums[0]));
            return ret;
        }
        
        for (int i = 0; i < n; i++)
        {
            string tmp = to_string(nums[i]);
            if (i != n-1 && nums[i+1] == nums[i]+1)
            {
                tmp += "->";
                while(nums[i+1] == nums[i] +1) i++;
                tmp += to_string(nums[i]);
            }
            ret.push_back(tmp);
        }
        return ret;
        
    }
};