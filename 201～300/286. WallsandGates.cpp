class Solution {
public:
    void search(vector<vector<int>>&r, int y, int x, int depth){
        if (y<0 || x<0 || y>=r.size() || x>=r[0].size()) return;
        if (r[y][x] == -1) return;
        if (r[y][x] == 0) return;
        if (r[y][x] <= depth) return;
        if (r[y][x] > depth || r[y][x] == INT_MAX) r[y][x] = depth;
        search(r,y-1,x,depth+1);
        search(r,y+1,x,depth+1);
        search(r,y,x-1,depth+1);
        search(r,y,x+1,depth+1);
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int y=0;y<rooms.size();y++){
            for (int x=0;x<rooms[0].size();x++){
                if (rooms[y][x]==0){
                    search(rooms,y+1,x, 1);
                    search(rooms,y-1,x, 1);
                    search(rooms,y,x-1, 1);
                    search(rooms,y,x+1, 1);
                }
            }
        }
    }
};