class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        
        int candidate1, candidate2, cnt1 = 0, cnt2 = 0;
        for (int num:nums) {
            if (num == candidate1) cnt1++;
            else if (num == candidate2) cnt2++;
            else if (cnt1 == 0) {
                candidate1 = num; cnt1++;
            }
            else if (cnt2 == 0) {
                candidate2 = num; cnt2++;
            }

            else { //other than the current majors
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0; cnt2 = 0;
        for (int num:nums) {
            if (num == candidate1) cnt1++;
            if (num == candidate2) cnt2++;
        }
        
        int thresh = nums.size()/3;
        cout << candidate1 <<", "<< candidate2 <<endl;
        cout << cnt1 << "," << cnt2;
        if (cnt1 > thresh) res.push_back(candidate1);
        if (candidate2 != candidate1 && cnt2 > thresh) res.push_back(candidate2);
        
        return res;
    }
};