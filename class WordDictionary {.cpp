class WordDictionary {
public:
    struct Node {
        bool end;
        Node *nodes[26];
        Node() {
            end=false;
            memset(nodes, 0, 26*sizeof(Node*));
        }
    } *root;

    WordDictionary() {
        root = new Node(), root->end = true;
    }

    void addWord(string word) {
        Node *cur=root;
        for (char c : word) {
            Node*& n = cur->nodes[c-'a'];
            cur = n ? n : (n=new Node());
        }
        cur->end = true;
    }

    bool search(string word) {
        return find(word, 0, root);
    }

    bool find(string& word, int pos, Node *from) {
        if (pos==word.length())
            return from->end;

        if (word[pos]=='.')
            for (auto& n : from->nodes)
                if (n && find(word, pos+1, n))
                    return true;
                else;
        else
            return from->nodes[word[pos]-'a'] ? find(word, pos+1, from->nodes[word[pos]-'a']) : false;

        return false;
    }
};