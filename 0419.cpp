// 找第一个，第一个就是上面和左面都没有！太机智了
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        int m = board.size();
        if (m == 0) return 0;
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && (i-1 < 0 || board[i-1][j] == '.') && (j-1 < 0 || board[i][j-1] == '.')) res++;
            }
        }
        return res;
    }
};