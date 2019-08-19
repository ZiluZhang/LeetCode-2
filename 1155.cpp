class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int mask = pow(10,9) + 7;
        vector<vector<long long>> dp(d+1, vector<long long>(target+1, 0));
        dp[0][0] = 1;
        // for (int i = 0; i <= d; i++) dp[i][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int k = 1; k <= target; k++) {
                int tmp = 0;
                for (int j = 1; j <= f; j++) {
                    if (k-j >= 0)
                        tmp = (tmp + dp[i-1][k-j]) % mask;
                }
                dp[i][k] = tmp % mask;
            }
        }
        return dp[d][target] % mask;
    }
};

// dp[i][k] = sum(dp[i-1][k-1~k-f])