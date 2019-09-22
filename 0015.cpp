class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (n < 3 || nums[n-1] < 0 || nums[0] > 0) return res;
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] > 0) break;
            int target = 0 - nums[i];
            int left = i+1, right = n-1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if (nums[left] + nums[right] < target) left++;
                else right--;
            }
        }
        return res;
    }
};