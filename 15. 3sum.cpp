class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret; // store result
        
        //check corner case
        if (nums.size()<3)
            return ret;
            
        //ensure no-desending
        sort(nums.begin(), nums.end());
        
        //find the triplet using two pointers
        for (int i = 0; i<nums.size()-2; i++)
        {
            int lptr = i+1; 
            int rptr = nums.size()-1;

            while (lptr < rptr) 
            {
                int sum = nums[lptr] + nums[rptr] + nums[i];
                 //check if they three add up to 0
                if (sum == 0)  //<i, lptr, rptr>
                {
                    vector<int> tmp; //store the triplet
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[lptr]);
                    tmp.push_back(nums[rptr]);
                    ret.push_back(tmp);
                    lptr++;
                    rptr--;
                    //jump duplication
                    while(nums[lptr] == nums[lptr-1]) lptr++;
                    while(nums[rptr] == nums[rptr+1]) rptr--;
                    while(nums[i]==nums[i+1]) i++;
                }
                else //move lptr and rptr
                if (sum <0) lptr++;
                else rptr--;
            }
        }
        return ret;
    }
};