class Codec {
    string formatNum(int n) {
        stringstream ss;
        ss << setw(4) << setfill('0') << n;
        return ss.str();
    }
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size();
        string s; //s = "n, len0+len1+len2+...+lenn, str0+str1+str2+...+strn"
        
        //add n
        s += formatNum(n);  //4bits
        
        //add lengths
        for (string word:strs)
            s += formatNum(word.length()); //4*n bits
            
        //add strings
        for (string word:strs) //sum(len(word)) bits
            s+= word;
            
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int n = stoi(s.substr(0, 4));
        vector<string> res(n, "");
        int i_len = 4, i_word = 4 + 4 * n;
        
        for (int i = 0; i < n; i++) {
            // abstract res[i] = s.substr(i_word, len)
            int len = stoi(s.substr(i_len, 4));
            string word = s.substr(i_word, len);
            res[i] = word;
            
            // pointers move forward
            i_len += 4;
            i_word += len;
        }
        
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));