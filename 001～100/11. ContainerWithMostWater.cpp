class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =  height.size(); //number of vertical lines
        int res = 0; //max area

        int l = 0, r = n-1;
        while (l < r) {
            int h = min(height[l], height[r]);
            res =  max(h * (r - l), res);

            if (height[l] <= h) l++;
            if (height[r] <= h) r--;
        }
        return res;
    }
};