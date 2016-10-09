class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if (n == 0) return 0;
        
        int sum = 0;
        vector<int> f(n, 0);

        for (int i = 0; i < n; i++) {
            sum += A[i];
            f[0] += i * A[i];
        }
        
        int res = f[0];
        for (int i = 1; i < n; i++) {
            f[i] = f[i - 1] - n * A[n - i] + sum;
            if (f[i] > res)
                res = f[i];
        }
        return res;
    }
};