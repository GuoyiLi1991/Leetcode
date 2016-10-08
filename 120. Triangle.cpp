// Sol1: DP
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) return 0;
        int n = triangle.size(); //number of rows
        
        
        int res = triangle[0][0];
       // for each step down, check tri[i + 1][j] and tri[i+1][j+1]
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int left = (j == 0)? INT_MAX : triangle[i - 1][j - 1];
                int right = (j == i)? INT_MAX: triangle[i - 1][j];
                triangle[i][j] += min(left, right);
            }
        }
        
        return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
    }
};

////////////
// Sol2: DFS, TLE
// Time: O(2^n), n is the depth
// Every time going down, choose from 2 options
class Solution {
    int best = INT_MAX;
    void dfs(int x, int y, int sum, vector<vector<int>>& A) {
        if (x == A.size()) {
            if (sum < best)
                best = sum;
            return;
        }
        
        dfs(x + 1, y, sum + A[x][y], A);
        dfs(x + 1, y + 1, sum + A[x][y], A);
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() > 20) return 0;
        dfs(0, 0, 0, triangle);
        return best;
        
    }
};

/////////
// Sol3: D&C, TLE
// Time: O(2^n), n is number of levels
// 好处：不用全局变量存结果
class Solution {
    int dfs(int x, int y, vector<vector<int>>& A) {
        if (x == A.size()) {
            return 0;  //stop adding
        }
        
        int left = dfs(x + 1, y, A);
        int right = dfs(x + 1, y + 1, A);
        
        return min(left, right) + A[x][y];
       
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return dfs(0, 0, triangle);        
    }
};

//////////
// !!!!!!!!!
// Sol4. Better D&C using dfs, ACCEPT, 56ms
// Time: O(n^2), n is depth
// # of nodes = 1+2+3+...+(n-1) = O(n^2), 因为有了ht,避免重复计算
class Solution {
    int dfs(int x, int y, vector<vector<int>>& A, 
    unordered_map<int, unordered_map<int, int>> &ht) {
        if (x == A.size()) {
            return 0;  //stop adding
        }
        
        if (ht.count(x)  && ht[x].count(y))
            return ht[x][y];
            
        int left = dfs(x + 1, y, A, ht);
        int right = dfs(x + 1, y + 1, A, ht);
        
        ht[x][y] = min(left, right) + A[x][y];
        return ht[x][y] ;
    }
    
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        unordered_map<int, unordered_map<int, int>> ht;
        return dfs(0, 0, triangle, ht);
    }
};


