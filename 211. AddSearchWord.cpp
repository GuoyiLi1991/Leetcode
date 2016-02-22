class TrieNode
{
public:
    bool is_word;
    TrieNode *next[26];
    TrieNode():is_word(false)
    {
        memset(next, 0, sizeof(next));
    }
};

class WordDictionary {
    TrieNode *root;
    bool search(TrieNode *root, string word)
    {
        TrieNode *ptr = root;
        for (int i = 0; i < word.size();i++)
        {
            int c = word[i] -'a';
            if (!ptr) break;
            if( word[i] != '.') 
                ptr = ptr->next[c];
            else // '.'
            {
                TrieNode *tmp = ptr;
                for (int j = 0; j < 26; j++)
                {
                    ptr = tmp ->next[j];
                    if (search(ptr, word.substr(i+1)))
                        return true;
                }
            }
        }
        return ptr && ptr->is_word;
    }
public:
    WordDictionary()
    {
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* ptr = root;
        for (char c:word)
        {
            int idx = c-'a';
            if (ptr->next[idx] == NULL) //hasn't inserted
            {
                //insert
                ptr->next[idx] = new TrieNode();
            }
            ptr = ptr->next[idx];
        }//all word inserted
        ptr->is_word = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(root, word);
    }
    

};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");