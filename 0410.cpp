class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int left = nums[0];
        long long right = 0;
        for (auto n: nums) {
            left = max(left, n);
            right += n;
        }
        long res = right;
        while (left < right) {
            long mid = left + (right - left) / 2;
            if (check(nums, mid, m)) {
                res = min(res, mid);
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
    
    bool check(vector<int>& nums, int k, int m) {
        int cnt = 0;
        long cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur + nums[i] > k) {
                cnt++;
                if (cnt > m) return false;
                cur = nums[i];
            } else {
                cur += nums[i];
            } 
        }
        cnt++;
        return (cnt <= m);
    }
};