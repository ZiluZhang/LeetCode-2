class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helper(0, word, i, j, board, visited)) return true;
            }
        }
        return false;
    }
    
    bool helper(int start, string word, int i, int j, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if (start == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || board[i][j] != word[start]) return false;
        visited[i][j] = true;
        bool res = helper(start+1, word, i+1, j, board, visited)
            || helper(start+1, word, i-1, j, board, visited)
            || helper(start+1, word, i, j+1, board, visited)
            || helper(start+1, word, i, j-1, board, visited);
        visited[i][j] = false;
        return res;
    }
};