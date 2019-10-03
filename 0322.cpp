class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> cnt(amount+1, INT_MAX);
        cnt[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i-coins[j] >= 0) {
                    cnt[i] = min(cnt[i-coins[j]]+1, cnt[i]);
                }
            }
        }
        return cnt[amount] == INT_MAX ? -1 : cnt[amount];
    }
};