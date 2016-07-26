class Solution {
    vector<int> serialize(string s) {
        vector<int> res;
        while (1) {
            int pos = s.find('.');
            if (pos != string::npos) {
                string cur(s.begin(), s.begin() + pos);
                s = s.substr(pos+1);
                res.push_back(stoi(cur));
            }
            else {
                res.push_back(stoi(s));
                break;
            }
        }
        return res;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = serialize(version1);
        vector<int> v2 = serialize(version2);
        
        //make equal length
        while (v1.size() < v2.size())
            v1.push_back(0);
        while (v2.size() < v1.size())
            v2.push_back(0);
            
        //comparison
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] > v2[i])
                return 1;
            else if (v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};