class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i < k; i++) {
            int cur = nums[nums.size()-1];
            nums.pop_back();
            nums.insert(nums.begin(), cur);
        }
        return;
    }
};