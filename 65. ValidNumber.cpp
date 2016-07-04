class Solution {
    bool isValid(string s)
    {
        if (s[0] == '+' || s[0] == '-') s = s.substr(1); //skip +/-
        bool isdot = false;

        int i = 0;
        while (i < s.size())
        {
            if (isdigit(s[i])) i++;
            else if (s[i] == '.' && s.size() != 1)
            {
                if (isdot == false)
                {
                    isdot = true;
                    i++;
                }
                else return false;
            }
            else break;
        }
        return s.size()!=0 && i == s.size();
    }
    bool isint(string s)
    {
        if (s[0] == '+' || s[0] == '-') s = s.substr(1); //skip +/-

        int i = 0;
        while (i < s.size() && isdigit(s[i])) i++;
        return s.size()!=0 && i == s.size();
    }
public:
    bool isNumber(string s) {
        if (s.size() == 0) 
            return false;
        //skipping zeros
        while (s.size()>0 && s[0] == ' ') s = s.substr(1);
        while (s.size() >0 && s[s.size()-1] == ' ') s = s.substr(0,s.size()-1);

        if (s.size() == 0) 
            return false;

        bool res = false;
        size_t pos = s.find('e');
        if (pos == string::npos)
            return isValid(s);
        else return isValid(s.substr(0,pos)) && isint(s.substr(pos+1));

    }
};