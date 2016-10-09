class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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


/////////// 
// Sol 2: Two pointers, set is not allowed
//  O(nlogn) for sorting
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0; //pointers for nums1 and nums2
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) //j waits
                i++;
            else if (nums1[i] > nums2[j]) //i waits
                j++;
            else { //nums1[i] == nums2[j]
                int tmp = nums1[i];
                if (res.empty())
                    res.push_back(tmp);
                else {//check if exist already
                    if (res.back() != tmp)  //make sure uniqueness
                        res.push_back(tmp);
                }
                i++; j++;
            }
        }
        
        return res;
    }
};