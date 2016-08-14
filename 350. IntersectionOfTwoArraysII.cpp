// elements in the result appears as many times as in both arrays
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ht;
        vector<int> res;
        for (int num: nums1) {
            ht[num]++;
        }
        for (int num: nums2) {
            if (ht.find(num) != ht.end()) {
                ht[num]--;
                if (ht[num] == 0) 
                    ht.erase(num);
                res.push_back(num);
            }
        }
        return res;
    }
};