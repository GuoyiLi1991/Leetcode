class Compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};
class Solution {
public:
    string rearrangeString(string str, int k) {
        int n = str.size();
        if (k == 0) return str;
        
        string res;
        int letter[26]; //count freq of each letter
        fill_n(letter, 26, 0);
        for (char c: str) 
            letter[c - 'a']++;
            
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> heap; // sorting <letter, cnt> by cnt
        for (int i = 0; i < 26; i++) {
            if (letter[i])
                heap.push(make_pair(char(i+'a'), letter[i]));
        }
        
        while (!heap.empty()) {
            int size = min(k, n);
            vector<pair<char, int>> cache;
            for (int i = 0; i < size; i++) {
                n--;
                if (heap.empty()) return "";
                pair<char, int> tmp = heap.top();
                heap.pop();
                res += tmp.first;
                if (--tmp.second > 0) cache.push_back(tmp);
            }
            for (auto p:cache) heap.push(p);
        }
        
        return res;

        
    }
};
