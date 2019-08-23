class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int n: nums) sum += n;
        int cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cur == sum - cur - nums[i]) return i;
            cur += nums[i];
        }
        return -1;
    }
};