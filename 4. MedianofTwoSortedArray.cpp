//////
// Sol1: Find kth smallest using minHeap
// Time: O(m + n)
class Solution {
    bool isEven(int a) {
        return a % 2 == 0;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int a: nums1)
            pq.push(a);
        for (int b: nums2)
            pq.push(b);
        int median = 0;
        int k = (m + n + 1)/2 - 1;
        while (k--)
            pq.pop();
        if (!isEven(m + n))
            return pq.top();
        else {
            median = pq.top();
            pq.pop();
            return (median + pq.top())/2.0;
        }
        
    }
};


//////////
// Sol2: Binary search
// Time: best O(log(m + n))
class Solution {
        /*
    对于一个长度为n的已排序数列a，若n为奇数，中位数为a[n / 2 + 1] , 
    若n为偶数，则中位数(a[n / 2] + a[n / 2 + 1]) / 2
    如果我们可以在两个数列中求出第K小的元素，便可以解决该问题
    不妨设数列A元素个数为n，数列B元素个数为m，各自升序排序，求第k小元素
    取A[k / 2] B[k / 2] 比较，
    如果 A[k / 2] > B[k / 2] 那么，所求的元素必然不在B的前k / 2个元素中(证明反证法)
    反之，必然不在A的前k / 2个元素中，于是我们可以将A或B数列的前k / 2元素删去，求剩下两个数列的
    k - k / 2小元素，于是得到了数据规模变小的同类问题，递归解决
    如果 k / 2 大于某数列个数，所求元素必然不在另一数列的前k / 2个元素中，同上操作就好。
    */
    double findKth(vector<int>& A, vector<int>& B, int Astart, int Bstart, int k) {
        int m = A.size(), n = B.size();
        
        // 边界情况，任一数列为空
        if (Astart >= m) 
            return B[Bstart + k - 1];
        if (Bstart >= n)
            return A[Astart + k - 1];
            
        if (k == 1) return min(A[Astart], B[Bstart]);
        
        int Amid = Astart + k/2 - 1, Bmid = Bstart + k/2 - 1;
        int Akey = (Amid >= m)? INT_MAX : A[Amid];
        int Bkey = (Bmid >= n)? INT_MAX : B[Bmid];
        
        if (Akey < Bkey) //exclude A[0, Amid]
            return findKth(A, B, Amid + 1, Bstart, k - k/2);
        else
            return findKth(A, B, Astart, Bmid + 1, k - k/2);
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if ((m + n) & 0x1) //odd
            return findKth(nums1, nums2, 0, 0, (m + n)/2 + 1);
        else
            return (findKth(nums1, nums2, 0, 0, (m + n)/2) + findKth(nums1, nums2, 0, 0, (m + n)/2 + 1)) /2;
    }
};

