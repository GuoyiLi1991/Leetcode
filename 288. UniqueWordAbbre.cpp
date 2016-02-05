// // Your ValidWordAbbr object will be instantiated and called as such:
// // ValidWordAbbr vwa(dictionary);
// // vwa.isUnique("hello");
// // vwa.isUnique("anotherWord");


class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> dic; //abbrevation dic
    
public:
    ValidWordAbbr(vector<string> &dictionary) {
        int n = dictionary.size();
        if (n==0) return;
        
        for (int i = 0; i<n; i++)
        {
            //convert string to abbr, and insert to dic
            string abbr = toAbbr(dictionary[i]);
            dic[abbr].insert(dictionary[i]);
            //cout << abbr <<endl;
        }
    }
    
    string toAbbr(string s)
    {
        int n = s.size();
        if(n<3) return s;
        string abbr=s[0]+to_string(n-2)+s[n-1];
        return abbr;
    }
    
    bool isUnique(string word) {
        string w_abbr = toAbbr(word);
        return (dic.find(w_abbr) == dic.end() ||(dic[w_abbr].find(word)!=dic[w_abbr].end() && dic[w_abbr].size()==1));
    }
};