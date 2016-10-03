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
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int numEdge = edges.size();
        if (numEdge < n - 1) return false;
        for (int i = 0; i < n; i++) {
            id.push_back(i);
        }
        
        for (auto& e: edges) {
            int x = e.first, y = e.second;
            if (find(x) == find(y)) return false; //circle!
            else unionSet(x, y);
        }
        
        //check if number of connected component is 1
        for (int i = 0; i < n - 1; i++) { 
            if (find(i) != find(i + 1))
                return false;
        }
        return true;
    }
};