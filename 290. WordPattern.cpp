class Solution {
    vector<string> tokenize(string str)
    {
        vector<string> words;
        stringstream ss(str);
        string word;
        
        while(getline(ss, word, ' '))
            words.push_back(word);
            
        return words;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = tokenize(str);
        int m = pattern.size(), n = words.size();
        if (m != n) return false;
        
        unordered_map<string, char> mp1;
        unordered_map<char, string>mp2;
        int i = 0;
        for (auto word: words)
        {
            if (mp1.find(word) == mp1.end())//new word
                mp1[word] = pattern[i];
            if (mp2.find(pattern[i]) == mp2.end())//new char
                mp2[pattern[i]] = word;
            if (ht1[pattern[i]] != words[i] || ht2[words[i]] != pattern[i])
                return false;
            i++;
        }
        
        return (mp1.size() == mp2.size());
        
    }
};

//////// my version, faster
// converted from 205. isomophic strings
class Solution {
    vector<string> getWords(string str) {
        vector<string> res;
        string word;
        stringstream ss(str);
        while (ss >>word)
            res.push_back(word);
        return res;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = getWords(str);
        int m = pattern.size(), n = words.size();
        if (m != n)
            return false;
        
        unordered_map<char, int> ht1;  // <char, pos>
        unordered_map<string, int> ht2; //<string, pos>
        for (int i = 0; i < m; i++) {
            int pos1 = ht1[pattern[i]];
            int pos2 = ht2[words[i]];
            
            if (pos1 && pos2) {
                if (pos1 != pos2)
                    return false;
            }
            else if (!pos1 && !pos2)
                ht1[pattern[i]] = ht2[words[i]] = i+1;
            else 
                return false;
        }
        return true;
    }
};