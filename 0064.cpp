class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        vector<vector<int>> dp(grid);
        for (int j = n-2; j >= 0; j--) dp[m-1][j] += dp[m-1][j+1];
        for (int i = m-2; i >= 0; i--) {
            dp[i][n-1] += dp[i+1][n-1];
            for (int j = n-2; j >= 0; j--) {
                dp[i][j] += min(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};