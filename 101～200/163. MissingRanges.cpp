class Solution {
    string range(int l, int r) {
        if (l + 1 > r - 1) //illegal range
            return "";
            
        string s = to_string(l + 1);
        if (r - 1 > l + 1)
            s = s + "->" + to_string(r - 1);
        return s;
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<string> res;
        string s;
        
        if (n == 0) 
            vector<string>{range(lower - 1, upper + 1)}; //lower and upper are inclusive

        // before nums
        s = range(lower - 1, nums[0]);
        if (s != "")
            res.push_back(s);
        
            
        int i = 0; //index of range
        while (i < n - 1) {
            while (i < n - 1 && nums[i] + 1 == nums[i + 1])
                i++;
            // found a gap between (nums[i] and nums[i + 1])
            if (i + 1 < n) {
                s = range(nums[i], nums[i + 1]);
                res.push_back(s);
                i++;
            }//else(nums[i] is the last one), break
        }

        s = range(nums[i], upper + 1);
        if (s != "")
            res.push_back(s);
        return res;
    }
};