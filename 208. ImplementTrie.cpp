class TrieNode {
public:
    bool is_word;
    TrieNode *next[26];
    // Initialize your data structure here.
    TrieNode() :is_word(false) {
        memset(next, 0, 26 * sizeof(TrieNode*));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *ptr = root;
        for (char c:word)
        {
            int key = c - 'a';
            if (ptr->next[key] == NULL) //not exisit
            {
                ptr->next[key] = new TrieNode();
            }
            ptr = ptr->next[key];
        } //word inserted completely
        
        ptr->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *pos = find(word);
        return (pos!=NULL) && (pos->is_word);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return (find(prefix) != NULL);
    }

private:
    TrieNode* root;
    TrieNode* find(string word)
    {
        TrieNode *ptr = root;
        for (char c:word)
        {
            if (ptr) ptr = ptr->next[c-'a'];
            else break;
        }
        return ptr;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

