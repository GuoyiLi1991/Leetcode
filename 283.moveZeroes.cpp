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
