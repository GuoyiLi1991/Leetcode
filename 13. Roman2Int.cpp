class Solution {    
public:
    int romanToInt(string s) {
        int n = s.length();
        if (n == 0) 
            return 0;
            
        map<char, int> dict = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = dict[s[n-1]];
        if (n == 1)
            return result;
        for (int i = n-2; i >= 0; --i) {
            if (dict[s[i+1]] > dict[s[i]]) {
                result -= dict[s[i]];
            }
            else 
                result += dict[s[i]];
        }
        
        return result;
    }
};