class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n ==0) return;
        if (m ==0)
        {
            nums1 = nums2;
            return;
        }
        
        int p1 = m-1;  //pointer in num1
        int p2 = n-1;   //pointer in num2
        for (int i = m+n-1; i>=0; --i)
        {
            
            if (p1 >-1 && p2>-1)
            {
                nums1[i] = nums1[p1]>nums2[p2]? nums1[p1--]:nums2[p2--];
                continue;  // Important to be here! A better way is to consider CORNER CASES first!!!
            }
            if (p1 == -1) //num1 over
            {
                nums1[i] = nums2[p2--];
                continue;
            }
            if (p2 == -1)  //num2 over
                return;
        }
        
    }
};
