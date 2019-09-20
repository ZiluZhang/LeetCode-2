class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if (n == 1) return 0;
        if ((n-1) % (K-1) != 0) return -1;
        vector<int> sum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i-1] + stones[i-1];
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = K; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int t = i; t < j; t += K-1) {
                    dp[i][j] = min(dp[i][j], dp[i][t] + dp[t+1][j]);
                }
                if ((j-i)%(K-1) == 0) {
                    dp[i][j] += sum[j+1] - sum[i];
                }
            }
        }
        return dp[0][n-1];
    }
};