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
            i++;
        }
        
        return (mp1.size() == mp2.size());
        
    }
};