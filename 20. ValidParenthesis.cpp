class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c:s)
        {
            if ( c == '{' || c == '(' || c == '[')
                st.push(c);
            else 
            {
                if (st.empty())  // *********Pay attention! ***********
                    return false;
                if (c == '}' && st.top() == '{'
                || c == ']' && st.top() == '['
                || c == ')' && st.top() == '(')
                    st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};



/////////////////////////////////////
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c:s) {
            switch (c) {
                case '[':
                case '{':
                case '(': st.push(c); break;
                case ']': 
                    if (st.empty() || st.top() != '[' ) 
                        return false;
                    st.pop();break;
                case '}':
                    if (st.empty() || st.top() != '{' ) 
                        return false;
                    st.pop();break;
                case ')':
                    if (st.empty() || st.top() != '(') 
                        return false;
                    st.pop();break;
            }
        }
        return st.empty();
    }
};