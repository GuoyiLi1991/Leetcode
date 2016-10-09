class Solution {
public:
    string getPermutation(int n, int k) {
        int total[10]; //total number of permutations
        total[0] = 1;
        for (int i = 1; i <= 9; i++) {
            total[i] = i * total[i-1];
        }
        
        string res;
        if (k > total[n])
            return res;
        string numSet = "123456789";
        while (n > 0) {
            int tmp = (k-1) / total[n-1];
            res += numSet[tmp];
            numSet.erase(numSet.begin() + tmp); //each number can only be used ONCE
            k -= tmp * total[n-1];
            n--;
        }
        return res;
    }
};

/////////////////////////////////////////////////
/* For record purpose only.
 * This version works when test individully, 
 * but TLE when submit.
 */
class Solution {
    int factorial(int k) {
        if (k == 1)
            return k;
            
        return k * factorial(k-1);
    }
    void backtracking(string &res, string &permutation, const int n, const int k, vector<bool> & visited, int &order) {
        if (permutation.size() == n) {
            order++;
            if (order == k)
                res = permutation;
            return;
        }
        
        for (int i = 1; i <= n; i++) {
            if (visited[i-1] == false) {
                permutation += char(i + '0');
                visited[i-1] = true;
                
                backtracking(res,permutation, n,k, visited, order);
                
                visited[i-1] = false;
                permutation.pop_back();
            }
        }
    }
public:
    string getPermutation(int n, int k) {
        
        if (n <1 || n > 9 || k > factorial(n))
            return "";
        string res,p;
        vector<bool> visited(n, false);
        
        int order = 0;
        backtracking(res,p, n, k, visited, order);
        return res;
        /***********************************/
    }
};


