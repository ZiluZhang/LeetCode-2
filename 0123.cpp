class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int mini = prices[0];
        for (int i = 1; i < n; i++) {
            mini = min(prices[i], mini);
            left[i] = max(left[i-1], prices[i] - mini);
        }
        int maxi = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxi = max(prices[i], maxi);
            right[i] = max(right[i+1], maxi - prices[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};