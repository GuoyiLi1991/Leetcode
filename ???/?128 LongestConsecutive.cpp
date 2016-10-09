class Solution {
public:
int longestConsecutive(vector<int>& nums) {
    unordered_map<int,bool> mp;
    int ret = 0;
    for(const auto x:nums)
        mp[x] = true;
    for(const auto x : mp)
        if(x.second)
        {
            int left = x.first,right = x.first+1;
            while(mp.count(left) && mp[left])
                mp[left--] = false;
            while(mp.count(right) && mp[right])
                mp[right++] = false;
            ret = max(ret,right - left  - 1);
        }
    return ret;
}
};