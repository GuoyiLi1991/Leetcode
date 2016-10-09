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
private:
    TrieNode* root;

    TrieNode* find(string word)
    {   //given a string, find its position in trie
        TrieNode *ptr = root;
        for (char c:word)
        {
            int key = c - 'a';
            if (ptr->child[key] != NULL)
                ptr = ptr->next[key];
            else 
                return NULL;
        }
        return ptr;
    }

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
        return (pos!=NULL) && (pos->is_word); //differenciate it from intermediate node
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return (find(prefix) != NULL);
    }


};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

