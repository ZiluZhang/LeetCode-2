class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size(), n = T.size();
        int minLen = INT_MAX;
        string res;
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= min(n, i); j++) {
                dp[i][j] = (S[i-1] == T[j-1]) ? dp[i-1][j-1] : dp[i-1][j];
            }
            if (dp[i][n] != -1) {
                int len = i - dp[i][n];
                if (minLen > len) {
                    res = S.substr(dp[i][n], len);
                    minLen = len;
                }
            }
        }
        return res;
    }
};