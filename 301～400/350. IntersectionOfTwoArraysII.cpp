// Sol 1: use hash table
//elements in the result appears as many times as in both arrays
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

//////////////////////
// Sol 2: Two pointers
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) //j waits
                i++;
            else if (nums1[i] > nums2[j]) //i waits
                j++;
            else {
                res.push_back(nums1[i]);
                i++; j++;
            }
        }
        return res;
    }
};