struct Cmp{
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        if (k == 0) return res;
        
        unordered_map<int, int> ht; //<num, freq>
        for (int num: nums) {
            if (ht.find(num) == ht.end()) //not found in hash table
                ht[num] = 1;
            else 
                ht[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq(ht.begin(), ht.end());
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        return res;
      
    }
};