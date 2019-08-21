class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int len = matrix.size();
        if (len == 0) return 0;
        int col = matrix[0].size();
        int maxlen = 0;
        int prev = 0;
        vector<int> dp(col+1, 0);
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= col; j++) {
                int tmp = dp[j];
                if (matrix[i-1][j-1] == '1') {
                    dp[j] = min(min(dp[j-1], prev), dp[j]) + 1;
                    maxlen = max(maxlen, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = tmp;
            }
        }
        return maxlen * maxlen;
    }
};