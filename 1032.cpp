class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> next;
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            next.push_back(NULL);
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& word) {
        TrieNode* tmp = root;
        for (int i = word.length()-1; i >= 0; i--) {
            char c = word[i];
            if (!tmp->next[c-'a']) {
                tmp->next[c-'a'] = new TrieNode();
            }
            tmp = tmp->next[c-'a'];
        }
        tmp->isWord = true;
    }
    
    bool findWord(string word) {
        TrieNode* tmp = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            if (!tmp->next[word[i]-'a']) return false;
            tmp = tmp->next[word[i]-'a'];
            if (tmp->isWord) return true;
        }
        return false;
    }
};

class StreamChecker {
public:
    int maxLen;
    Trie t;
    string cur;
    StreamChecker(vector<string>& words) {
        t = Trie();
        maxLen = 0;
        cur = "";
        for (string w: words) {
            t.insert(w);
            int curLen = w.length();
            maxLen = max(maxLen, curLen);
        }
    }
    
    bool query(char letter) {
        cur += letter;
        if (cur.length() > maxLen) {
            cur = cur.substr(1);
        }
        return t.findWord(cur);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */