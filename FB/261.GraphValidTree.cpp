///// DFS
class Solution {
    bool dfs(vector<vector<int>>& g, vector<bool>& visited, int cur, int pre) {
        if (visited[cur] == true) //has circle
            return false;
        visited[cur] = true;
        for (auto a:g[cur]) {
            if (a != pre && !dfs(g, visited, a, cur)) //not connected
                return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // construct graph
        vector<vector<int>> g(n, vector<int>());
        for (auto a:edges) {
            //indirect
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        
        vector<bool> visited(n, false);
        if (!dfs(g, visited, 0, -1)) return false; //has circle
        for (auto a: visited) {
            if (a == false)
                return false;
        }
        return true;
    }
};

///// BFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> g(n, set<int>());
        for (auto e : edges) {
            g[e.first].insert(e.second);
            g[e.second].insert(e.first);
        }
        
        queue<int>q;
        unordered_set<int> v;
        q.push(0);
        v.insert(0);
        
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            
            for (auto a:g[t]) {
                if (v.find(a) != v.end()) //visited, circle
                    return false;
                v.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        
        return v.size() == n; //all visited
    }
};

//// Union find
/* 对于解决连通图的问题很有效，思想是我们遍历节点，
    如果两个节点相连，我们将其roots值连上，这样可以帮助我们找到环:
    初始化roots数组为-1，然后对于一个pair的两个节点分别调用find函数，
    得到的值如果相同的话，则说明环存在，返回false，
    不同的话，我们将其roots值union上
*/

class Solution {
    int find(vector<int>& roots, int i) {
        while (roots[i] != -1)
            i = roots[i];
        return i;
    }
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<int> roots(n, -1);
        for (auto e : edges) {
            int v1 = e.first, v2 = e.second; 
            int x = find(roots, v1);
            int y = find(roots, v2);
            
            if (x == y) return false;
            roots[x] = y;
        }
       // return edges.size() == n - 1;
       return true;
    }
};

