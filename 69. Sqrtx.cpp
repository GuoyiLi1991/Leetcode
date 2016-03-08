class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) return 0;
        if (x == 1) return 1;
        
        int l = 0, r = x;
        while (l<r-1)
        {
            int mid = l + (r-l) /2;
            if (x/mid == mid) return mid;
            if (x/mid > mid) //check right
                l = mid;
            else 
                r = mid;
        }
        return l;
    }
};