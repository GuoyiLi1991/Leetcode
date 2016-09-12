// Sol1. Heap. Did not take advantage of "Sorted"
// 102ms.

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