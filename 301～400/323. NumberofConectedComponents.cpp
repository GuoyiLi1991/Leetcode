//union-find, merge-find, disjoint-set
// O(|E|)
class Solution {
    vector<int> id; //x.parent
    void makeSet(int n)
    {
        for (int i = 0; i<n; i++)
            id.push_back(i);
    }
    
    int find(int x)
    {
        if (x == id[x]) return x;
        else return find(id[x]);
    }
    
    void unions(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        id[xRoot] = yRoot;
    }
    
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int ret = n;
        makeSet(n);
        for (auto edge : edges)
        {
            int x = find(edge.first);
            int y = find(edge.second);
            if(x != y) 
            {
                unions(x,y);
                ret--;
            }
        }
        return ret;
    }
};


// Redo
class Solution {
    vector<int> id;
    int find(int x) {
        if (x == id[x])
            return x;
        return find(id[x]);
    }
    void unionSet(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        id[xRoot] = yRoot;
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int numEdge = edges.size();
        for (int i = 0; i < n; i++)
            id.push_back(i);
        
        int res = n;   
        for (auto& e : edges) {
            int x = e.first;
            int y = e.second;
            if (find(x) != find(y)) {
                unionSet(x, y);
                res--;
            }
        }
        
        return res;
    }
};



////////
// BFS
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        for (auto &e : edges) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        
        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            res++;
            
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int tmp = q.front();
                q.pop();
                
                visited[tmp] = true;
                for (int nei : g[tmp]) {
                    if (!visited[nei])
                        q.push(nei);
                }
                    
            }
        }
        
        return res;
    }
};

//////////
// DFS
class Solution {
    void dfs(vector<vector<int>>& g, vector<bool>& visited, int cur) {
        if (visited[cur]) return;
        
        visited[cur] = true;
        for (int i = 0; i < g[cur].size(); i++) {
            dfs(g, visited, g[cur][i]);
        }
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int>());
        for (auto &e : edges) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        
        int res = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            
            res++;
            dfs(g, visited, i);
        }
        
        return res;
    }
};
