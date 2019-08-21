class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int res = nums[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == res) {
                cnt++;
            } else {
                cnt--;
                if (cnt == 0) {
                    res = nums[i+1];
                }
            }
        }
        return res;
    }
};