class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        unordered_set<int> ht;
        for (int num: nums1) {
            ht.insert(num);
        }
        unordered_set<int> res_set;
        for (int num: nums2) {
            if (ht.find(num) != ht.end())
                res_set.insert(num);
        }
        return vector<int>(res_set.begin(), res_set.end());
    }
};