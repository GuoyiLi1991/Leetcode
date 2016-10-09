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




///////////////////
class Solution {
public:
    bool isNumber(string s) {
        bool meetSign = false;
        bool hasResult = false;
        bool meetPoint = false;
        bool meetE = false;

        while (s.size() && s[0] == ' ')
            s = s.substr(1);
        while(s.size() && s[s.size()-1] == ' ')
            s = s.substr(0, s.size()-1);
        
            
        for (char c:s) {
            if (!isdigit(c)) {
                if (isspace(c))
                    return false;
                if (c == '.') {
                    if (meetPoint ||meetE) //two digital points
                        return false;
                    meetPoint = true;
                }
                if (c == '+' || c == '-') {
                    if (meetSign || meetPoint || hasResult) //more than one signs
                        return false;
                    meetSign = true;
                }
                if  (isalpha(c)) {
                    if (c == 'e') {
                        if (meetE || !hasResult)
                            return false;
                        meetE = true;
                        meetSign = false; 
                        meetPoint = false;
                        hasResult = false; //need to at least wait for one more digit
                    }
                    else return false;
                }
                
            }
            else hasResult  = true;
        }
        return hasResult;
    }
};