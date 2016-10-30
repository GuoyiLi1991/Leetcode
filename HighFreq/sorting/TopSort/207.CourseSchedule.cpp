class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size(); //num of edges
        if (n < 2) return true;

        int degrees[numCourses];//hash table, storing in-degree
        fill_n(degrees, numCourses, 0);
        
        //construct graph
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto e: prerequisites) {
            g[e.second].push_back(e.first);
            degrees[e.first]++;
        }
        
        //keep a set of vertices with no incoming edges
        queue<int> untaken;
        for (int i = 0; i < numCourses; i++) {
            if (degrees[i] == 0)
                untaken.push(i);
        }
        
        int nLeft = numCourses;
        while (!untaken.empty()) {
            //remove v from the set
            int v = untaken.front();
            untaken.pop();
            nLeft--;

            //remove edges from graph that starts with v, if turns out to be indegree 0, add to set
            while (!g[v].empty()) {
                int m = g[v].back();
                g[v].pop_back();
                if (--degrees[m] == 0)
                    untaken.push(m);
            }
        }
        
        if (nLeft != 0) return false;
        else return true;
        
    }
};

//////////
// Sol2. DFS, very slow
class Solution {
    bool canFinish(vector<vector<int>>& g, vector<bool>& visited, int pos) {
        if (visited[pos] == true)
            return false;
            
        visited[pos] = true;
        for (int v : g[pos]) {
            if (!canFinish(g, visited, v))
                return false;
        }
        visited[pos] = false;
        
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto e : prerequisites) {
            g[e.second].push_back(e.first);
        }
        
        vector<bool> visited(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!canFinish(g, visited, i))
                return false;
        }
        
        return true;
    }
};

//////////
// Sol3. DFS+memorization
class Solution {
    bool canFinish(vector<vector<int>>& g, vector<bool>& visited, int pos, vector<bool>& mem) {
        if (mem[pos] == true)
            return true;
        if (visited[pos] == true)
            return false;
            
        visited[pos] = true;
        for (int v : g[pos]) {
            if (!canFinish(g, visited, v, mem))
                return false;
        }
        visited[pos] = false;
        
        mem[pos] = true;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        vector<bool> mem(numCourses, false);
        for (auto e : prerequisites) {
            g[e.second].push_back(e.first);
        }
        
        vector<bool> visited(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!canFinish(g, visited, i, mem))
                return false;
        }
        
        return true;
    }
};

//////////
// Sol3 - 2 Even better, saved the hash table by setting visited
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>());
        vector<int> visit(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
};

