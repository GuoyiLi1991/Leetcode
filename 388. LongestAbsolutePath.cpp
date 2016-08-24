class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.size();
        if (n == 0) return 0;
        
        stack<int> st;
        int i = 0;
        int res = 0;
        string line;
        while (i < n + 1) {
            if (i != n && input[i] != '\n')
                line += input[i];
            else { //parse the line
                int level = line.find_first_not_of('\t');
                line = line.substr(level); //remove tabs
                
                while (level < st.size()) //find the correct level
                    st.pop();
                    
                if (st.empty())     // first level, push cur len
                    st.push(line.size());
                else {              // already under some folder, push cur len + previous len + '\'
                    st.push(line.size() + st.top() + 1);
                }
                
                if (line.find('.') != string::npos && st.top() > res) //store longest until now
                    res = st.top();
                line = "";
            }
            i++;
        }
    
        return res;
    }
};