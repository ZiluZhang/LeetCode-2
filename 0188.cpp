class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        if (k >= n) return getMax(prices);
        vector<int> g(k+1, 0);
        vector<int> l(k+1, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i-1];
            for (int j = k; j >= 1; j--) {
                l[j] = max(g[j-1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
    
    int getMax(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        }
        return res;
    }
};