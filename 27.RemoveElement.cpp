class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        for (int i = 0; i<n; i++)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[(n--)-1];
                i--;
            }
        }
        return n;
        
    }
};

////////////////////////////////
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0;
        for (int i: nums) {
            if (i != val)
                nums[l++] = i;
        }
        nums.resize(l);
        
        return l;
    }
};