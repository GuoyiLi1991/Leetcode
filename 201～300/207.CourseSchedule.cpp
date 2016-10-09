class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        int n = prerequisites.size(); //num of edges
        if (n < 2) return true;

        int degrees[numCourses];//hash table, storing in-degree
        fill_n(degrees, numCourses, 0);
        
        //construct graph
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto e: prerequisites) {
            g[e.first].push_back(e.second);
            degrees[e.second]++;
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

