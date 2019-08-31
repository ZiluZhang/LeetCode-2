class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) return nums;
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        left[0] = 1;
        for (int i = 1; i < len; i++) {
            left[i] = left[i-1] * nums[i-1];
        }
        right[len-1] = 1;
        for (int i = len-2; i >= 0; i--) {
            right[i] = right[i+1] * nums[i+1];
        }
        vector<int> res;
        for (int i = 0; i < len; i++) {
            res.push_back(left[i] * right[i]);
        }
        return res;
    }
};