class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int curMin = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < curMin) {
                curMin = prices[i];
            } else if (prices[i] - curMin > res) {
                res = prices[i] - curMin;
            }
        }
        return res;
    }
};