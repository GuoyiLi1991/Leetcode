//////// 
// Sol1: Dynamic Programming
// Time: O(n), Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int frontProd = 1, backProd = 1;
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            frontProd *= nums[i];
            backProd *= nums[n - 1 - i];
            res = max(res, max(frontProd, backProd));
            
            frontProd = (frontProd == 0)? 1 : frontProd;
            backProd = (backProd == 0)? 1 :backProd;
        }
        
        return res;
    }
};

////////
// Sol 2:
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int pMax = 0, nMax = 0; //positive max, negative max
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                swap(pMax, nMax);
            //pMax and nMax will be seperated by 0's
            pMax = max(pMax * nums[i], nums[i]); 
            nMax = min(nMax * nums[i], nums[i]);
            res = max(res, pMax);
        }
        return res;
    }
};
