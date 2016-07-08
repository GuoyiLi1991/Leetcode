class Solution {
public:
    int myAtoi(string str) {
        //----------Preprocessing-------------//
        //skipping zeros
        while (str.size()>0 && str[0] == ' ') 
            str = str.substr(1);

        //dealing with +/-
        int sign = 1;
        if (str[0] == '+' || str[0] == '-') 
        {
            if (str[0] == '-')
                sign = -1;
            str = str.substr(1);
        }
        //trim the num part
        size_t pos= str.find_first_not_of("0123456789");
        if (pos != string::npos)
            str = str.substr(0, pos);
            
        int n = str.size();
        if (n == 0)
            return 0;
        
        //----------------------------------

        //next, real int
        int num = 0;
        for (int i = n-1; i >= 0 ; i--)
        {
            num += (str[i]-'0') * pow(10, n-1-i);

        }
        if (num < 0)  //overflow
            return sign>0? 2147483647 : -2147483648;
        
        return sign*num;
    }
};

////////////////////////////////
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        bool flag = false; //whether already met a sign
        bool hasResult = false;
        int sign = 1;
        
        for (char c:str) {
            if (!isdigit(c)) {
                if (isspace(c) && !hasResult && !flag)
                    continue;
                if (c == '-' || c == '+') {
                    if (flag) //second time
                        return res * sign;  //illegal
                    flag = true;
                    if (c == '-') 
                        sign = -1;
                    continue;
                }
                return res * sign;
            }
            
            int digit = c - '0';
            res = res * 10 + digit;
            if (res >= INT_MAX) {
                if (sign > 0)
                    return INT_MAX;
                else return (res == INT_MAX)? -INT_MAX:INT_MIN;
            }

            hasResult = true;
        }
        return res* sign;
    }
};