//Sol1. Three passes
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        int maxL[n], maxR[n];
        maxL[0] = 0;
        maxR[n - 1] = 0;
        
        int maxH = height[0];
        for (int i = 1; i < n; i++) {
            maxL[i] = maxH;
            if (height[i] > maxH)
                maxH = height[i];
        }
        
        maxH = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxR[i] = maxH;
            if (height[i] > maxH)
                maxH = height[i];
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(min(maxL[i], maxR[i]) - height[i], 0);
        }
        return res;
    }
};

// Sol2. Two pointers
// Time:O(n), space O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        int res = 0;
        int l = 0, r = n - 1;
        int maxLeft = 0, maxRight = 0;
        
        while (l < r) {
            if (height[l] <= height[r]) {
                res += max(maxLeft - height[l], 0);
                maxLeft = max(maxLeft, height[l]);
                l++;
            }
            else {
                res += max(maxRight - height[r], 0);
                maxRight = max(maxRight, height[r]);
                r--;
            }
        }
        
        return res;
    }
};