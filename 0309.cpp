class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> buy(n, 0);
        vector<int> sell(n, 0);
        buy[0] = 0-prices[0];
        for (int i = 1; i < n; i++) {
            int last_sell = 0;
            if (i >= 2) last_sell = sell[i-2];
            buy[i] = max(buy[i-1], last_sell - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
        }
        return sell[n-1];
    }
};