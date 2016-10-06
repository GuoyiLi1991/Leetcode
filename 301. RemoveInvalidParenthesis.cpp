// Sol1. BFS
// 把给定字符串排入队中，然后取出检测其是否合法，若合法直接返回，不合法的话，我们对其进行遍历
// 对于遇到的左右括号的字符，我们去掉括号字符生成一个新的字符串
// 如果这个字符串之前没有遇到过，将其排入队中，我们用哈希表记录一个字符串是否出现过。
// 我们对队列中的每个元素都进行相同的操作，直到队列为空还没找到合法的字符串的话，那就返回空集，


class Solution {
    bool isValid(string s) {
        int cnt = 0;
        
        for (char c : s) {
            if (c == '(') cnt++;
            if (c == ')') cnt--;
            if (cnt < 0) return false;
        }
        
        return cnt == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        
        queue<string> q;
        unordered_set<string> visited; //avoid duplication
        q.push(s);
        visited.insert(s);

        bool found = false;
        
        while (!q.empty()) {
            string tmp = q.front();
            q.pop();
            
            if (isValid(tmp)) {
                res.push_back(tmp);
                found = true;
            }
            
            if (found) continue;

            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] != '(' && tmp[i] != ')')
                    continue;
                string t = tmp.substr(0, i) + tmp.substr(i + 1); //remove tmp[i]
                
                if (!visited.count(t)) { //haven't checked
                    q.push(t);
                    visited.insert(t);
                }
            }
        }

       return res;
    }
};


