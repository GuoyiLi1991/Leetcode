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

////////////////
// in place and consice
// replace '.' by ' ', and take advantage of istringstream
/////////////////
class Solution {
public:
    int compareVersion(string version1, string version2) {
        std::replace(version1.begin(), version1.end(), '.', ' ');
        std::replace(version2.begin(), version2.end(), '.', ' ');
        
        /* or .... notice the & 
        for (char &c:version1) {
            if (c == '.')
                c = ' ';
        }
        for (char &c:version2) {
            if (c == '.')
                c = ' ';
        }
        */
        
        istringstream s1(version1), s2(version2);
        while (1) {
            int n1 = (s1 >> n1)? n1 : 0;
            int n2 = (s2 >> n2)? n2 : 0;
            if (n1 > n2) return 1;
            if (n2 > n1) return -1;
            if (!s1 && !s2) return 0;
        }
    }
};