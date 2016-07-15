////////////// Simple recursion /////////////////
class Solution {
    void generateParenthesis(vector<string> &res, string str, int n, int lc, int rc) {
        //lc : how many '(' already added
        //rc: how many ')' already added
        if (lc == n && rc == n) {
            res.push_back(str);
            return;
        }

        if (lc < n) 
            generateParenthesis(res, str + "(", n, lc + 1, rc);
        if (rc < lc)
            generateParenthesis(res, str + ")", n, lc, rc + 1);
            
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        generateParenthesis(res, str, n, 0, 0);
        return res;
    }
};

/////////////////////// Backtracking, so fast //////////////////
class Solution {
    void construct(vector<string> &res, string &parens, int left, int right) { //backtracking
        //left: how many '(' is still needed
        //right: how many ')' is still needed
        if (!left && !right) { //need no more
            res.push_back(parens);
            return;
        }
        
        if (left > 0) {  //not enough '('
            parens += "(";
            construct(res, parens, left - 1, right);
            parens.pop_back();
        }
        
        if (right > left) { //not enough ')' to close
            parens += ")";
            construct(res, parens, left, right -1);
            parens.pop_back();
        }
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        construct(res, str, n, n);
        return res;
    }
};