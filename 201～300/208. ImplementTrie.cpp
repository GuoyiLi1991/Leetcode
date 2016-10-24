// typedef struct TrieNode {
//     TrieNode **next;
//     bool is_word;
//     TrieNode() : is_word(false) {
//         //memset(next, 0, 26 * sizeof(TrieNode*));
//         next = new TrieNode*[26]();
//     }
// } TrieNode;
/////////////////////////
// Sol1: Array of TrieNode *
// Not space efficient
class TrieNode {
public:
    TrieNode* next[26];
    bool is_word = false;

    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
    }
}

class Trie {

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        
        for (char letter : word) {
            int key = letter - 'a';
            if (p->next[key] == NULL) {
                p->next[key] = new TrieNode();
            }
            p = p->next[key];
        } //word is completely inserted
        
        p->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *end = find(word);
        return (end != NULL && end->is_word);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }

private:
    TrieNode* root;
    TrieNode *find(string prefix) {
        // return the position of the end of prefix
        // if not found, return NULL
        
        TrieNode *p = root;
        for (char letter : prefix) {
            int key = letter - 'a';
            if (p->next[key] == NULL) //not found
                return NULL;
            else
                p = p->next[key];
        }
        
        return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


////////////////////////////////////////////
// Version 2: HashMap Version
// Saved some space in some sense
// Modify: each node(except root) stores a 'c',
//     check existence becomes if (p->next.count(c) == 0)
class TrieNode {
public:
    char c;
    unordered_map<char, TrieNode*> next;
    bool is_word = false;
    
    TrieNode(){};
    TrieNode(char wc){
        c = wc;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (p->next.count(c) == 0) {
                p->next[c] = new TrieNode(c);
            }
            p = p->next[c];
        }
        
        p->is_word = true;
    }
    
    TrieNode* find(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            if (p->next.count(c) == 0)
                return NULL;
            p = p->next[c];
        }
        return p;
    }

    bool startsWith(string prefix) {
        return (find(prefix) != NULL);
    }
    
    bool search(string word) {
        TrieNode *end = find(word);
        return (end != NULL && end->is_word);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
