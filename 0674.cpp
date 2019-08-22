class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = nums.size();
        int res = 1;
        if (len <= 1) return len;
        int i = 0;
        while (i < len) {
            int cnt = 1;
            while (i + 1 < len && nums[i] < nums[i+1]) {
                cnt++;
                i++;
            }
            i++;
            res = max(res, cnt);
        }
        return res;
    }
};