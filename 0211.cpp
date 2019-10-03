class WordDictionary {
public:
    struct TrieNode {
        public:
        bool flag;
        TrieNode* child[26];
        TrieNode() {
            flag = false;
            for (int i = 0; i < 26; i++) child[i] = NULL;
        }
    };
    TrieNode* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* tmp = root;
        for (char c: word) {
            if (!tmp->child[c-'a'])
                tmp->child[c-'a'] = new TrieNode();
            tmp = tmp->child[c-'a'];
        }
        tmp->flag = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchPattern(word, root, 0);
    }
    
    bool searchPattern(string word, TrieNode* p, int i) {
        if (i == word.size()) return p->flag;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (p->child[j] && searchPattern(word, p->child[j], i+1)) return true;
            }
            return false;
        } else {
            return p->child[word[i]-'a'] && searchPattern(word, p->child[word[i]-'a'], i+1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */