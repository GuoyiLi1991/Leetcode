class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> lastseen;
        if (s.size() == 0 || k == 0) return 0;
        
        int maxSize = 0, curSize = 0;
        int start;
        for (int i = 0; i < s.size(); i++) {
            if (lastseen.count(s[i]) || lastseen.size() < k) {//allow adding a new key
                curSize++;
            }
            else {//not found, and exceeds k distinct, shrink window size
                start = i;
                for (auto& item : lastseen) { //remove the key of the oldest char
                    if (item.second < start)
                        start = item.second;
                }
                curSize = i - start;
                lastseen.erase(s[start]);
            }
            
            lastseen[s[i]] = i;
            maxSize = max(maxSize, curSize);
        }
        
        return maxSize;
    }
};