// use a stack to store status before '('
// Time: O(n), space: O(k)?
class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        if (s == "") return 0;
        
        int res = 0;
        stack<int> st; //store sign outside the parentheses
        st.push(1); //initialization, make sure st is not empty
        int sign = 1;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push(st.top() * sign);
                sign = 1;
            }
            else if (c == ')') {
                st.pop();
            }
            else if (c == '+')
                sign = 1;
            else if (c == '-')
                sign = -1;
            else { //meet number
                // int num = c - '0';
                // i++;
                // while (i < s.size() && isdigit(s[i])) {
                //     num = num * 10 + (s[i] - '0');
                //     i++;
                // } //stop when s[i] is not digit
                // i--;
                int l = i;
                i = s.find_first_not_of("0123456789", l);
                num = stoi(s.substr(l, i));
                res += num * sign * st.top();
            }
        }
        
        return res;
    }
};