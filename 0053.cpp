class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        int curSum = nums[0];
        int res = curSum;
        for (int i = 1; i < len; i++) {
            curSum = max(curSum + nums[i], nums[i]);
            res = max(res, curSum);
        }
        return res;
    }
};