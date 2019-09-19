class Solution {
public:
    struct TrieNode {
    public:
        TrieNode* child[26];
        string str;
        TrieNode() {
            str = "";
            for (int i = 0;  i< 26; i++) child[i] = NULL;
        }
    };
    
    struct Trie {
    public:
        TrieNode* root;
        Trie() {
            root = new TrieNode();
        }
        void insert(string str) {
            TrieNode* p = root;
            for (int i = 0; i < str.length(); i++) {
                char c = str[i];
                if (!p->child[c-'a']) p->child[c-'a'] = new TrieNode;
                p = p->child[c-'a'];
            }
            p->str = str;
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        if (m == 0) return {};
        int n = board[0].size();
        if (n == 0) return {};
        Trie t;
        for (string w: words) t.insert(w);
        vector<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(i, j, t.root->child[board[i][j]-'a'], board, res, visited);
            }
        }
        return res;
    }
    
    void helper(int i, int j, TrieNode* p, vector<vector<char>>& board, vector<string>& res, vector<vector<bool>>& visited) {
        if (!p) return;
        if (p->str.length() > 0) {
            res.push_back(p->str);
            p->str.clear();
        }
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        visited[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int a = i + dir[k][0];
            int b = j + dir[k][1];
            if (0 <= a && a < m && 0 <= b && b < n && !visited[a][b] && p->child[board[a][b]-'a']) {
                helper(a, b, p->child[board[a][b]-'a'], board, res, visited);
            }
        }
        visited[i][j] = false;
    }
};