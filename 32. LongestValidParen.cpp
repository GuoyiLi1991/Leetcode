////// my version, TLE when n > 150
class Solution {
    bool isValid(string s) {
        vector<char> st;
        for (char c:s)
        {
            if (c == '(' )
                st.push_back(c);
            else 
            {
                if (st.empty())  // *********Pay attention! ***********
                    return false;
                if (c == ')' && st.back() == '(')
                    st.pop_back();
                else return false;
            }
        }
        return st.empty();
    }
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n > 150) return 0;
        int res = 0;
        vector<set<string>> ht(n + 1, set<string>{});
        for (int i = 0; i < n - 1; i++) {
            while (s[i] == ')') i++;
            int j = 2;
            while (i + j <= n)
            {
                string sub = s.substr(i, j++);
                
               // cout << i << "," << j <<endl;
                int tmp = sub.size();
                set<string> tmpset = ht[tmp];
                if (!tmpset.empty() && tmpset.find(sub) != tmpset.end() || isValid(sub))
                {
                    ht[tmp].insert(sub);
                    res = max(res, tmp);
                    //cout << sub <<endl;
                }
            }
        }
        return res;
    }
};

////// working version with a stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), res = 0;
        stack<int> st;
        
        //push index of breaking points into the stack
        for (int i  = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop(); //found a valid string
                    else st.push(i); //still waiting
                }
                else // ')' && st.empty()
                    st.push(i);
            }
        }
        
        if (st.empty()) return n;
        
        int end = n;
        while (!st.empty()) {
            int start = st.top();
            st.pop();
            res = max(res, end - start - 1);
            end = start;
        }
        res = max(res, end - 0);
        
        return res;
        
    }
};

