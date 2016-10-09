//////////
// Sol1. DFS, 9ms
class Solution {
    void dfs(vector<vector<char>>& grid, int m, int n, int i, int j) {
        grid[i][j] = '0';
        if (i > 0 && grid[i - 1][j] == '1')
            dfs(grid, m, n, i - 1, j);
        if (j > 0 && grid[i][j - 1] == '1')
            dfs(grid, m, n, i, j - 1);
        if (i < m - 1 && grid[i + 1][j] == '1')
            dfs(grid, m, n, i + 1, j);
        if (j < n - 1 && grid[i][j + 1] == '1')
            dfs(grid, m, n, i, j + 1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); if (m == 0) return 0;
        int n = grid[0].size(); if (n == 0) return 0;
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0;  j < n; j++) {
                if (grid[i][j] == '0') continue;
                ans++;
                dfs(grid, m, n, i, j); //set all '1's that connected to it to '0'
            }
        }
        
        return ans;
    }
};




//////////////////////////
// Sol2. BFS, 9ms
class Solution {
    void visit(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
    }
    
    bool isIsland(vector<vector<char>>& grid, int i, int j) {
        return grid[i][j] == '1';
    }
    
    void BFS(vector<vector<char>>& grid, int m, int n, int i, int j) {
        queue<pair<int, int>> q; //queue of <i, j>
        q.push(make_pair(i, j));
        visit(grid, i, j);
        
        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            i = tmp.first;
            j = tmp.second;
            
            if (i > 0 && isIsland(grid, i - 1, j)) {
                q.push(make_pair(i - 1, j));
                visit(grid, i - 1, j);
            }
            
            if (j > 0 && isIsland(grid, i, j - 1)) {
                q.push(make_pair(i, j - 1));
                visit(grid, i, j - 1);
            }
            
            if (i < m - 1 && isIsland(grid, i + 1, j)) {
                q.push(make_pair(i + 1, j));
                visit(grid, i + 1, j);
            }
            
            if (j < n - 1 && isIsland(grid, i, j + 1)) {
                q.push(make_pair(i, j + 1));
                visit(grid, i, j + 1);
            }
        
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); if (m == 0) return 0;
        int n = grid[0].size(); if (n == 0) return 0;
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0;  j < n; j++) {
                if (grid[i][j] == '0') continue;
                ans++;
                BFS(grid, m, n, i, j); //set all '1's that connected to it to '0'
            }
        }
        
        return ans;
    }
};









////////
// Sol3. Union find, 6ms
class Solution {
    vector<int> id;
    int num_components;
    
    void make_set(vector<int>& id, int m, int n) {
        id.reserve(m * n);
        for (int i = 0; i < m * n; i++) 
            id[i] = i;
    }
    
    int find(int x) {
        if (x == id[x])
            return x;
        return find(id[x]);
    }
    
    void unions(int x, int y) {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot) {
            id[xRoot] = yRoot;
            num_components--;
        }
    }
    
    int to1d(int i, int j, int col) { //2d index to 1d
        return i * col + j;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        make_set(id, m , n);
        num_components = (grid[0][0] == '1');

        // i == 0
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == '0') continue;
            num_components++;
            if (grid[0][j - 1] == '1')
                unions(to1d(0, j, n), to1d(0, j - 1, n));
        }

        // j == 0
        for (int i = 1; i < m; i++) {
            if (grid[i][0] == '0') continue;
            num_components++;
            if (grid[i - 1][0] == '1')
                unions(to1d(i, 0, n), to1d(i - 1, 0, n)); 
        }
        
        //i != 0 && j != 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == '0') continue;
                num_components++;
                if (grid[i - 1][j] =='1') {
                    unions(to1d(i, j, n), to1d(i - 1, j, n));
                }
                if (grid[i][j - 1] == '1') {
                    unions(to1d(i, j, n), to1d(i, j - 1, n));
                }
            }
        }
        
        return num_components;
  
    }
};



////////
class Solution {
    vector<int> id;
    int num_components;
    
    void make_set(vector<int>& id, int m, int n) {
        id.reserve(m * n);
        //num_components = m * n;
        for (int i = 0; i < m * n; i++) 
            id[i] = i;
    }
    
    int find(int x) {
        if (x == id[x])
            return x;
        return find(id[x]);
    }
    
    void unions(int x, int y) {
        int xRoot = find(x), yRoot = find(y);
        if (xRoot != yRoot) {
            id[xRoot] = yRoot;
            num_components--;
        }
    }
    
    // // bool hasNeighbour(vector<vector<char>>& grid, int i, int j) {
    // //     if (i == 0 && j == 0) return false;
    // //     if (i == 0 && grid[0][j - 1]) return true;
    // //     if (j == 0 && grid[0][i - 1]) return true;
    // //     if (grid[i - 1][j] || grid[i][j - 1]) return true;
    // //     return false;
    // // }
    int to1d(int i, int j, int col) { //2d index to 1d
        return i * col + j;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        // int res = (grid[0][0] == '1');
        // for (int j = 1; j < n; j++) {
        //     if (grid[0][j] == '1' && grid[0][j - 1] == '0')
        //         //if (m == 1 || m > 1 && grid[1][j] == '0')
        //             res++;
        // }
        
        // for (int i = 1; i < m; i++) {
        //     if (grid[i][0] == '1' && grid[i - 1][0] == '0')
        //       // if (n == 1 || n > 1 && grid[i][1] == '0')
        //             res++;
        // }
        
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) 
        //         if (grid[i][j] == '1' && grid[i - 1][j] == '0' && grid[i][j - 1] == '0')
        //             res++;
        // }
        
        // return res;
        // for (int i = 0; i < m; i++) 
        //     for (int j = 0; j < n; j++)
        //         if (grid[i][j] == '1')
        //             num_components++;
        
        make_set(id, m , n);
        num_components = (grid[0][0] == '1');
        // i == 0
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == '1') {
                num_components++;
                if (grid[0][j - 1] == '1')
                    unions(to1d(0, j, n), to1d(0, j - 1, n));
            }
        }
        // j == 0
        for (int i = 1; i < m; i++) {
            if (grid[i][0] == '1') {
                num_components++;
                if (grid[i - 1][0] == '1')
                    unions(to1d(i, 0, n), to1d(i - 1, 0, n)); 
            }
        }
        
        //i != 0 && j != 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] == '0') continue;
                num_components++;
                if (grid[i - 1][j] =='1') {
                    unions(to1d(i, j, n), to1d(i - 1, j, n));
                }
                if (grid[i][j - 1] == '1') {
                    unions(to1d(i, j, n), to1d(i, j - 1, n));
                }
            }
        }
        
        return num_components;
  
    }
};