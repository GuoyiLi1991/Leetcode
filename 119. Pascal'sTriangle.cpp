// Method 1. ans[j] = ans[j]+ ans[j-1]
// 		O(k) space, add from the back
// Method2. Using the math
// 		the kth element in nth row is 
// 		C(n,k) = n!/(n-k)!/k!
// 		C(n,k-1) = n!/(n-k+1)!/(k-1)!
// 		Thus, c(n,k) = c(n, k-1) * (n-k+1)/k


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1,1);
        for (int i = 1; i< rowIndex; i++)
        {
            for (int j = i; j>0; --j)
            ans[j] = ans[j-1]+ ans[j];
        }
        return ans;
    }
};

