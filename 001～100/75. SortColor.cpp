class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int mid = l;
        while (mid <= r)
        {
            int tmp = nums[mid];
            if (tmp == 1) mid++;
            if (tmp == 0) swap(nums[mid++], nums[l++]);
            if (tmp == 2) swap(nums[mid], nums[r--]);
            /**** Notice when tmp ==2, mid does not increase       ***/
            /**** because you do not know that nums[r] is, 0 or 1  **/
        }
    }
};


/****神方法********/
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        for (int num: nums)
        {
            if (num == 0) { nums[b++] = 2; nums[w++] = 1; nums[r++] = 0; }
            if (num == 1) { nums[b++] = 2; nums[w++] = 1; }
            if (num == 2)  b++;
        }
    }