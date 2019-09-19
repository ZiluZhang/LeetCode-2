class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int cur = 0, i = 0;
        int res = 0;
        while (cur < len-1) {
            res++;
            int prev = cur;
            for (; i <= prev; i++) {
                cur = max(cur, i + nums[i]);
            }
        }
        return res;
    }
};