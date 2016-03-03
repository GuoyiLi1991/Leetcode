class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {};
        for (char c:t) 
            map[c]++;
            
        int counter = t.size();
        int begin = 0, end = 0; //two pointers in s
        int minLength = INT_MAX, head = 0;
        while(end < s.size())
        {
            if (map[s[end++]]-- > 0)
            {
                counter--; //found one more char in t that is contained
                // map[s[end]]--;
                // end++;
            }
            while(counter == 0) //valid
            {
                if (begin+minLength > end)
                {
                    head = begin;
                    minLength = end - begin;
                }
                
                if (map[s[begin++]]++ == 0)
                {
                    counter++; //invalid, need to progress right ptr to find this char
                    // map[s[begin]]++;
                    // begin++;
                }
            }
        }
        return (minLength == INT_MAX)? "":s.substr(head, minLength);
    }
};