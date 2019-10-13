class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        if (n == 1) return weights[0];
        int left = weights[0], right = 0;
        for (auto w : weights) {
            left = max(left, w);
            right += w;
        }
        int res = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // cout << mid << ' ' << check(weights, D, mid) << endl;
            if (check(weights, D, mid)) {
                res = min(res, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
    
    bool check(vector<int>& weights, int D, int k) {
        int n = weights.size();
        int cnt = 0;
        int cur = 0;
        for (auto w : weights) {
            if (cur + w > k) {
                cnt++;
                cur = w;
                if (cnt > D) return false;
            } else {
                cur += w;
            }
        }
        if (cur > 0) cnt++;
        return (cnt <= D);
    }
};