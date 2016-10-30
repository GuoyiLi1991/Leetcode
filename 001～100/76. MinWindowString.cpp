class Solution {
    bool covers(int freq[256], int requires[256]) {
        for (int i = 0; i < 256; i++) {
            if (requires[i] - freq[i] > 0)
                return false; //need more
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int tfreq[256];
        int sfreq[256];
        fill_n(sfreq, 256, 0);
        fill_n(tfreq, 256, 0);
        for (char tc : t) 
            tfreq[tc]++;
        
        string res;

        int l = 0, r = 0;
        while (r < s.size() && !covers(sfreq, tfreq)) {
            sfreq[s[r]]++;

            if (covers(sfreq, tfreq)) //got a solution
            {
                while (sfreq[s[l]] - 1 >= tfreq[s[l]]) {
                    sfreq[s[l]]--;
                    l++;
                };
                
                int curLen = r - l + 1;
                if (res.empty() || curLen < res.size())
                    res = s.substr(l, curLen);
                
                sfreq[s[l]]--; ////
                l++;
            }

            r++; //new start
        }
                
        return res;
            
    }
};