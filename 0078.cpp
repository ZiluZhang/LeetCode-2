class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return {};
        vector<vector<int>> res;
        vector<int> cur;
        getAll(cur, nums, 0, res);
        return res;
    }
    
    void getAll(vector<int> cur, vector<int> nums, int s, vector<vector<int>>& res) {
        if (s >= nums.size()) {
            res.push_back(cur);
            return;
        }
        getAll(cur, nums, s+1, res);
        cur.push_back(nums[s]);
        getAll(cur, nums, s+1, res);
    }
};