class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int>::iterator it1, it2;
        it1 = nums.begin(); 
        it2 = nums.end();
        for (int i=0; i<n,it1!=it2; i++,it1++)
        {
            if (nums[i] == 0) 
            {
                nums.erase(it1);
                it2--;
                nums.push_back(0);
                i--;it1--;
            }
        }
        
    }
};


//more consise - use two pointers
// remember the end of original array
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n<2) return;
        
        int l =0, r = n-1;
        while (l<n && l<r)
        {
            if (nums[l] == 0)
            {
                nums.erase(nums.begin()+l);
                nums.push_back(0); 
                r--;
            }
            else ++l;
        }
    }
};

//////////
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while (r < n) {
            if (nums[r]) {
                nums[l++] = nums[r];
            }
            r++;
        }
        while (l < n)
            nums[l++] = 0;
            
    }
};