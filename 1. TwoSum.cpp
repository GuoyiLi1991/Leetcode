class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);
        unordered_map<int,int> mymap;
        for (int i =0; i<n; i++)
        {
            if (mymap.find(nums[i]) == mymap.end())
                mymap[target-nums[i]] = i;
            else // the pair found
            {
                ans[0] = mymap[nums[i]]+1;
                ans[1] = i+1;
                return ans;
            }
        }
    }
};


/* Another way, just implement the hash table using a BIG array
// FASTER
vector<int> twoSum(vector<int>& nums, int target) 
    {
        static int MAX = 99999;
        static int DELT = 49999;
        vector<int> ans;
        int x[MAX];
        memset(x, 0, sizeof(x));
        for (int i = 0; i < nums.size(); i++)
        {
            if (x[nums[i] + DELT])
            {
                ans.push_back(x[nums[i] + DELT]);
                ans.push_back(i + 1);
                return ans;
            }
            x[target - nums[i] + DELT] = i + 1;
        }
    }

*/