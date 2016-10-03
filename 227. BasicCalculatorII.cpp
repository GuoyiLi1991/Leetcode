////
// Sol1: didn't work with long int....
// Check out sol2
class Solution {
    int op(int op1, int op2, char c) {
        switch (c) {
            case '+': return op1 + op2;
            case '-': return op1 - op2;
            case '*': return op1 * op2;
            case '/': return op1 / op2;
        };
        return 0;
    }
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        if (s == "") return 0;
        
        int n = s.size();
        queue<char> signs;
        stack<int> numbers;
        int l = 0, r = 0;
        while (l <= r && r < n) {
            while (r < n && isdigit(s[r]))
                r++;
            numbers.push(stoi(s.substr(l, r)));
            //now s[r] is a sign or end
            if (r == n) break;
            //deal with signs
            if (s[r] == '+' || s[r] == '-') {
                signs.push(s[r]);
                l = ++r;
                continue;
            }
            else { // * or /
                char tmp = s[r++];
                int op1, op2;
                op1 = numbers.top();
                numbers.pop();
                // find the post operands
                l = r;
                while (r < n && isdigit(s[r]))
                    r++;
                op2 = stoi(s.substr(l, r));
                numbers.push(op(op1, op2, tmp));
            }
        }
        int res = numbers.top();
        numbers.pop();
        while (!signs.empty()) {
            char c = signs.front();
            res = op(res, numbers.top(), c);
            signs.pop();
            numbers.pop();
        }
        return res;
    }
};



////////////
// Sol2.
class Solution {
public:
    int calculate(string s) {
        istringstream ss("+ " + s + " +");

        char op;
        long long res = 0;
        long long term = 0, n;
        while (ss >> op) {
            if (op == '+' || op == '-') {
                res += term;
                ss >> term;
                term *= ((op == '+')? 1 : -1);
            }
            else{
                ss >> n;
                if (op == '*')
                    term *= n;
                if (op == '/')
                    term /= n;
            }
        }
        
        return res;
    }
};


//逆波兰
class Solution {
public:
    int calculate(string s) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        int res = 0;
        if (s.empty()) return 0;
        
        vector<int> st;
        int i = 0;
        int j = s.find_first_not_of("0123456789");
        string term = s.substr(i, j);
        st.push_back(stoi(term));
        while (j < s.size()) {
            char op = s[j];
            i = ++j;
            j = s.find_first_not_of("0123456789", i);
            term = s.substr(i, j);
            // cout << op << endl;
            if (op == '+') 
                st.push_back(stoi(term));
            else if (op == '-')
                st.push_back(-stoi(term));
            else if (op == '*' )
                st.back() *= stoi(term);
            else 
                st.back() /= stoi(term);
                
            i = j;
        }
        
        for (int i = st.size() - 1; i >= 0; i--) {
            res += st[i];
        }
        
        return res;
    }
        
};