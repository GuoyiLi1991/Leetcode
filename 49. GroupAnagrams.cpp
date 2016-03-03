class Solution {
    string strSort(string str)
    {
        char mp[26] = {0};
        for (char c:str)
            mp[c-'a']++;
        str = "";
        for (int i = 0; i<26; i++)
            while(mp[i]--)
                str += char(i+'a');
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if (strs.size() == 0)
            return ret;
        unordered_map<string, multiset<string>> dic;
        for (int i = 0; i< strs.size(); i++)
        {
            string tmp = strs[i];
            //sort(tmp.begin(), tmp.end());
            tmp = strSort(tmp);
            dic[tmp].insert(strs[i]);
        }
        
        //insert multiset to vector of vector
        for (auto msetkey:dic)
        {
            multiset<string> mset = msetkey.second;
            vector<string> anagram(mset.begin(), mset.end());
            ret.push_back(anagram);
        }
    }
};