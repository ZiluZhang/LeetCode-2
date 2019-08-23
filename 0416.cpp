class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (int num: nums) {
            for (int k = target; k >= num; k--) {
                if (dp[k-num]) dp[k] = true;
            }
            if (dp[target]) return true;
        }
        return dp[target];
    }
};