//O(n) time, O(1) space
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        
        int i, j; //two pointers, i is faster
        for (i = 0, j = 0; i<s.length() && j<=s.length(); i++)
        {
            if (s[i] != ' ') //continue scanning
                continue;
            else  //meet next space
            {
                reverse(s.begin()+j, s.begin()+i);
                j = i+1;
            }
        }
        //reverse the last substring
        reverse(s.begin()+j, s.end());
    }
};