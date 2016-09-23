class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size(); 
        
        //construct dependency graph
        map<char, vector<char>> g;
        map<char, int> degrees; 
        for (string word : words)
            for (char letter : word)
                degrees[letter] = 0;
        
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];
            for (int j = 0; j < min(s1.size(), s2.size()); j++) {
                if (s1[j] != s2[j]) { //from s2[j] to s1[j]
                    g[s1[j]].push_back(s2[j]);
                    degrees[s2[j]]++;
                    break;
                }
            }
            /* Misunderstaning: if each word are in lexicographical order, then:
            for (int j = 1; j < s.size(); j++) { //from s[j] to s[j - 1]
                vector<char> tmp = g[s[j]];
                if (s[j] == s[j - 1] || find(tmp.begin(), tmp.end(), s[j - 1]) != tmp.end())
                    continue;
                g[s[j]].push_back(s[j - 1]);
                degrees[s[j]] = degrees[s[j]];
                degrees[s[j - 1]]++;
            }
            */
        }
        // for (auto d : degrees) {
        //     cout << d.first << "," <<d.second <<endl;
        // }
        
        //topology sort
        queue<char> untaken;
        for (auto item : degrees){
            if (item.second == 0)
                untaken.push(item.first);
        }
        
        string res;
        while (!untaken.empty()) {
            //remove v from untaken
            char v = untaken.front();
            untaken.pop();
            if (res.find(v) == std::string::npos)
                res.push_back(v);
            
            //remove all edges starting with v and decrease the destinated degree
            while (!g[v].empty()) {
                char dest = g[v].back();
                g[v].pop_back();
                if (--degrees[dest] == 0)
                    untaken.push(dest);
            }
        }

        if (res.size() != degrees.size()) return "";
        else return res;
        
    }
};