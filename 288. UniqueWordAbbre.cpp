class ValidWordAbbr {
    string toAbbr(string s){
        int n = s.size();
        if (n < 3)
            return s;
        return s[0] + to_string(n-2) + s[n - 1];
    }
    // hashing <abbr, set<string>>
    unordered_map<string, set<string>> ht;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string s: dictionary) {
            string abbr = toAbbr(s);
            ht[abbr].insert(s);
        }
    }

    bool isUnique(string word) {
        string abbr_word = toAbbr(word);
        if (ht.find(abbr_word) == ht.end())
            return true;
        else {
            set<string> similar = ht[abbr_word];
            if (similar.size() > 1)
                return false;
            else 
                return *(similar.begin()) == word;
        }
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");


