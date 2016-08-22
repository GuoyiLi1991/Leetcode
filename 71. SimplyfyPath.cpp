/* Another way to seperate the string by deliminator '/':
 *
 istringstream ss(path);
 string token;

 while (getline(ss, token, '/')) {
    //if token == ......
 }

 */

class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        string res;
        stack<string> st;
        for (int i = 0; i < n; i++){
            string tmp;
            while (i < n && path[i] != '/') {
                tmp += path[i++];
            }
            if (tmp == "" || tmp == ".") continue; // multiple slashes or stays still
            if (tmp == "..") {
                if (!st.empty())
                    st.pop(); //pop parent dir
            }
            else
                st.push(tmp);
        }
        //build simplified path
        while (!st.empty()) {
            string tmp = st.top();
            st.pop();
            res = '/' + tmp + res;
        }
        return  (res == "")? "/": res;
    }
};

