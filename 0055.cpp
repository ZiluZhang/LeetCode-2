class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        // vector<bool> dp(len, false);
        // dp[len-1] = true;
        int right = len-1;
        for (int i = len-2; i >= 0; i--) {
            if (i + nums[i] >= right) {
                // dp[i] = true;
                right = i;
            }
        }
        return right == 0;
    }
};