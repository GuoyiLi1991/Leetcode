class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        vector<pair<int, int>> heights;
        for (auto &b : buildings) {
            int l = b[0];
            int r = b[1];
            int h = b[2];
            
            heights.push_back({l, -h});//if l equals, smaller h comes later
            heights.push_back({r, h});
        }
        
        sort(heights.begin(), heights.end());
        multiset<int> heap;
        heap.insert(0);
        int pre = 0, cur = 0;
        for (auto &h : heights) {
            if (h.second < 0) 
                heap.insert(-h.second);
            else
                heap.erase(heap.find(h.second));
                
            cur = *heap.rbegin(); //current largetst height
            if (cur != pre) { //avoid multiple lines with same height
                res.push_back({h.first, cur});
                pre = cur;
            }
        }
        
        return res;
        
        
    }
};