class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (n <= numRows || numRows == 1)
            return s;
        
        int delta = 2 * numRows - 2;
        int numCols_first = (n-1)/delta + 1;
        int numCols_last = (n-numRows)/delta + 1;
        
        string res;
        
        vector<int> order;
        //first line
        for (int i = 0; i < numCols_first; ++i) {
            int idx = i * delta;
            order.push_back(idx);
            res += s[idx];
        }
        
        //middle lines
        for (int i = 1; i < numRows-1; ++i) {
            res += s[i];
            for (int j = 1; j <numCols_first; ++j) {
                res += s[order[j] - i];
                if (order[j] + i < n)
                    res += s[order[j] + i];
           }
           if  (numCols_first*delta -i < n)
                res += s[numCols_first*delta -i];
        }
        
        //last line
        for (int i = 0; i < numCols_last; ++i) {
            res += s[i * delta + numRows -1];
        }
        cout << numCols_first << "," <<numCols_last<<endl;

        
        return res;
    }
};