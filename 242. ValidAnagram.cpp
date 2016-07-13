class Solution {
public:
    ////////// method 1 using hashtable O(n) //////////
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        if (s == t)
            return true;
          
        vector<int> ht(26, 0); // hash table of letters  
        for (int i = 0; i < s.size(); i++) {
            ht[s[i] - 'a']++;
            ht[t[i] - 'a']--;
        }
        
        for (int i  = 0; i < 26; i++) {
            if (ht[i] != 0)
                return false;
        }
        return true;
    }

    //////// method 2 using sort O(nlogn) //////////////
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        if (s == t)
            return true;
            
        sort(s.begin(), s.end()); //O(nlogn)
        sort(t.begin(), t.end());
        return s == t;
    }
          
};

/* 
 * Follow up:
 * What if the inputs contain unicode characters? 
 * How would you adapt your solution to such case?
 */