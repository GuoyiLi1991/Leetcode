// class FreqCmp{
// public:
//     bool operator()(pair<char, int> &a, pair<char, int> &b){
//             if (a.second < b.second) 
//                 return true;
//             else if (a.second > b.second)
//                 return false;
//             else
//                 return a.first < b.first;
//     };
// };
class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        int n = str.size();
        
        map<char, int> char_freq;
        for (char c : str) char_freq[c]++;
        
        priority_queue<pair<int, char>> maxHeap; //<freq, char>
        for (auto &item : char_freq) {
            maxHeap.push({item.second, item.first});
        }
        
        string res;
        while (!maxHeap.empty()) {
            vector<pair<char, int>> cache;
            
            int loops = min(k, n);
            for (int j = 0; j < loops; j++) {
                if (maxHeap.empty()) return "";
                
                auto cur = maxHeap.top();
                res += cur.first;
                n--;
                
                if (--cur.second > 0) cache.push_back(cur);
                maxHeap.pop();
            }
            
            for (auto &a : cache) maxHeap.push(a);
        }
        return res;
    }
};