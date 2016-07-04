class Solution {
    void DFS(vector<vector<char>> &grid, int x, int y)  //8ms
    {
        grid[x][y] = '0';
        if (x>0 && grid[x-1][y] == '1')
            DFS(grid, x-1, y);
        if (x<grid.size()-1 && grid[x+1][y] == '1')
            DFS(grid, x+1, y);
        if (y>0 && grid[x][y-1] == '1')
            DFS(grid, x, y-1);
        if (y<grid[0].size()-1 && grid[x][y+1] == '1')
            DFS(grid, x, y+1);
    }
    bool island(vector<vector<char>>&grid, int x, int y)
    {
        return grid[x][y] == '1';
    }
    void visited(vector<vector<char>>&grid, int x, int y)
    {
        grid[x][y] = '0';
    }
    void BFS(vector<vector<char>> &grid, int x, int y)
    {
        queue<vector<int>> q;
        q.push({x,y});
        grid[x][y] = '0';//visited(grid, x, y);

        
        while(!q.empty())
        {
            vector<int> tmp = q.front();
            x = tmp[0];
            y = tmp[1];
            q.pop();
            
            if (x>0 && island(grid, x-1, y))
            {
                q.push({x-1, y});
                //visited(grid, x-1, y);
                grid[x-1][y] = '0';
            }
            if (x<grid.size()-1 && island(grid,x+1, y))
            {
                q.push({x+1, y});
                grid[x+1][y] = '0';//visited(grid, x+1, y);
            }
            if (y>0 && island(grid, x, y-1))
            {
                q.push({x, y-1});
                grid[x][y-1] = '0';//visited(grid, x, y-1);
            }
            if (y<grid[0].size()-1 && island(grid, x, y+1))
            {
                q.push({x, y+1});
                grid[x][y+1] = '0';//visited(grid, x, y+1);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int  row = grid.size(), col = (row == 0)?0:grid[0].size();
        if (!row || !col)
            return 0;
        int ans = 0;
        for (int i = 0; i<row; ++i)
            for (int j = 0; j<col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    BFS(grid, i, j);
                }
            }
        return ans;
    }
};