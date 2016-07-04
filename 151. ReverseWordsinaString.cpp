class Solution {
public:
    void reverseWords(string &s) {
        string ss;
        int pos = 0;
        for (char c:s) {
            if (c != ' ') {
                if (ss != "" && pos == 0)
                    ss = " " + ss;
                ss.insert(ss.begin() + pos++, c);
            }
            else {
                pos = 0;
            }
        }
        s = ss;
    } // very slow...
    
};

//////Method 2: tokenize using stringstream (beat 93%)////////
class Solution {
    vector<string> tokenize(string &s) {
        vector<string> res;
        stringstream ss(s);
        string word;
        while (getline(ss, word, ' ')) // while (ss>>word)
        {
            if (word != "")
                res.push_back(word);
        }
        return res;
    }
public:
    void reverseWords(string &s) {
        vector<string> words = tokenize(s);
        if (words.size() == 0) 
        {
            s = "";
            return;
        }
        s = words[0];
        for (int i = 1; i< words.size(); i++)
        {
            s = words[i] + " " + s;
        }
        
    }
};

/////////// Method 3: In-place ((from forum))/////
// Runtime: O(n), Space O(1)
class Solution {
    void reverseWord(string &s, int i, int j) // reverse a single word or the entire string
    {
        while (i < j)
        {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
        }
    }
public:
    void reverseWords(string &s) {
        int i = 0, j = 0; //find the range of a word
        int l = 0;
        int n = s.length();
        int wordCnt = 0;
        
        while (true)
        {
            while (i < n && s[i] == ' ') //removing leading spaces
                i++;
            if (i == n) //only spaces in s
                break;
            //find a beginning of a word
            if (wordCnt != 0)
                s[j++] = ' ';
            l = j;
            while (i < n && s[i] != ' ') //still in the word found just now
                s[j++] = s[i++];
            //s[j] now is a space
            reverseWord(s, l, j-1);
            wordCnt++;
        }
        
        s.resize(j); 
        reverseWord(s, 0, j-1); //reverse the whole string
    }
};
