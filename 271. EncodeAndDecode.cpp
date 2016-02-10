class Codec {
public:
    //helper func: formatNum
    string formatNum(int n)
    {
        stringstream ss;
        ss <<setw(4)<<setfill('0')<<n;
        return ss.str();
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string s; //[num_strs, len1+len2+..., str1+str2...]
        int num_strs = strs.size();
        int idx = 0;
        int idx_str = 4 + num_strs *4;
        
        s += formatNum(num_strs);
        
        for (int i = 0; i<num_strs; i++)
        {
            s+=formatNum(strs[i].length());
        }
        for (int i = 0; i<num_strs; i++)
        {
            s+=strs[i];
        }
        
        return s;
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int idx = 0;
        
        int nums_strs = stoi(s.substr(idx,4));
        idx = idx+4;
        if (nums_strs == 0) return strs;
        
        int idx_str = nums_strs *4 +4; //idx of the first string
        
        for (int i = 0; i<nums_strs; i++)
        {
            int len = stoi(s.substr(idx, 4));
            string tmp  = s.substr(idx_str, len);
            strs.push_back(tmp);

            idx += 4;
            idx_str += len;
        }
        
        return strs;
  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));