// Sol1. Heap. Did not take advantage of "Sorted"
// Time: O(n^2 logk) average and worst case
// 102ms.
/*
https://www.hrwhisper.me/leetcode-kth-smallest-element-sorted-matrix/
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if (m == 0) return -1;
        int n = matrix[0].size();
        if (n == 0) return -1;
        
        // keep a max-heap to store k min elements
        priority_queue<int> pq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++ j) {
                if (pq.size() >= k) {
                    if (matrix[i][j] < pq.top()) //remove pq.top and push
                        pq.pop();
                    else // ignore matrix[i][j]
                        continue;
                }
                pq.push(matrix[i][j]);
            }
        }
        return pq.top();
    }
};

// Sol2. A bit better
// O(klogk), worst case k = n^2
struct Node {
    int val, i, j;
    Node(int i, int j, int val) :i(i), j(j), val(val) {}
    bool operator < (const Node & x)const {
        return val > x.val;
    }
};
 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Node> q;
        int n = matrix.size();
        q.push(Node(0, 0, matrix[0][0]));
        while (--k > 0) {
            Node  x = q.top(); q.pop();
            if (x.i == 0 && x.j + 1 < n) q.push(Node(x.i, x.j + 1, matrix[x.i][x.j + 1]));
            if (x.i + 1 < n) q.push(Node(x.i + 1, x.j, matrix[x.i + 1][x.j]));
        }
        return q.top().val;
    }
};

// Sol3: Binary search for each row.. [Ignore that col is also sorted]
// Time: O(mlogn * logX)
//       x = max - min = A[m - 1][n - 1] - A[0][0]

/*我觉得用二分做最好，这个方法只要求行有序，和列有木有序并没有关系。 （或者列有序，行有序无序都没关系）
设L = min(matrix) R= max(matrix)  , mid =( L + R ) / 2 ，mid为我们猜测的答案。
然后对于每一行，找它在该行中第几大（也是二分，找上界），累加和K比较。
值得注意的是枚举 答案应该用下界， 因为猜想的解不一定在数组中，不断的收缩直到找到在数组中的元素为止。
查找一行需要log(n) ，有n行所以nlog(n)，最坏下需要查找log(X)次（X= int最大值的时候logX仅仅才为32），X为最大最小数差值。  所以总复杂度为O(nlogn *  logX)
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int L = matrix[0][0], R = matrix[n - 1][n - 1];
        while (L < R) {
            int mid = L + ((R - L) >> 1);
            int temp = 0;
            for (int i = 0; i < n; i++) temp += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (temp < k) L = mid + 1;
            else R = mid;
        }
        return L;
    }
};


// Sol4 : [Best]Binary search, uses the "sorted"
// Similar to 240. Search in 2D matrix II
// O(nlogX)   其中X = max – min
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int L = matrix[0][0], R = matrix[n - 1][n - 1];
        while (L < R) {
            int mid = L + ((R - L) >> 1);
            int temp = search_lower_than_mid(matrix, mid, n);
            if (temp < k) L = mid + 1;
            else R = mid;
        }
        return L;
    }
    int search_lower_than_mid(const vector<vector<int>>& matrix, int x, const int n) {
        int i = n - 1, j = 0, cnt = 0;
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= x) {
                j++;
                cnt += i + 1;
            }
            else i--;
        }
        return cnt;
    }
};