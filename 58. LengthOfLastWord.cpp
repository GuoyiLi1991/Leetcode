class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        while(s!= "" && s[s.size()-1] == ' ')
            s = s.substr(0, s.size()-1);
            
        size_t pos = s.find_last_of(' ');
        return s.size()-1-pos;
    }
};