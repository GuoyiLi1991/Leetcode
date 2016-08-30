class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // letter count in magazine should not be less than ransomNote
        int ht[26];
        fill_n(ht, 26, 0);
        for (char c:magazine) {
            ht[c - 'a']++;
        }
        
        for (char c:ransomNote) {
            if (ht[c - 'a'])
                ht[c - 'a']--;
            else 
                return false;
        }
        return true;
    }
};