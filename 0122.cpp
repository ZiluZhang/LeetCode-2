class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int buy = -1;
        int sell = 1;
        int res = 0;
        while (i < n-1) {
            while (i+1 < n && prices[i] >= prices[i+1]) {
                i++;
            }
            buy = prices[i];
            while (i+1 < n && prices[i] <= prices[i+1]) {
                i++;
            }
            sell = prices[i];
            res += sell - buy;
        }
        return res;
    }
};