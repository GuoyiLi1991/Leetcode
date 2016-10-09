class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, end = 0; //window
        int begin = 0, minLength = INT_MAX; //result
        
        vector<int> mp(128,0);
        for (char c:t)
            mp[c]++;
            
        int counter = t.size();
        while (end < s.size())
        {
            if (mp[s[end]] >0) //s[end] is also in t
                counter--;
            mp[s[end]]--;
            end++;
            
            while(counter ==0) //t is completely matched
            {
                //save the current best first
                if (end-start < minLength)
                {
                    minLength = end-start;
                    begin = start;
                }
                
                //try to minimize the window
                if (mp[s[start]] == 0) //lost a target char in the window
                    counter++; //make it invalid, so counter!=0, try end++ again;
                mp[s[start]]++;
                start++;
            }
        }
        
        if (minLength == INT_MAX) //never got a valid window
            return "";
        return s.substr(begin, minLength);
    }
};