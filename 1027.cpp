class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, unordered_map<int, int>> dp;
        if (A.size() <= 1) {
            return A.size();
        }
        int res = 2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i+1; j < A.size(); ++j) {
                int diff = A[j] - A[i];
                if (!dp[diff].count(j)) {
                    dp[diff][j] = 2;
                }
                dp[diff][j] = max(dp[diff][i] + 1, dp[diff][j]);
                res = max(res, dp[diff][j]);
            }
        }
        return res;
    }
};