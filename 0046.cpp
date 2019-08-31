// backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        backtrack(n, nums, res, 0);
        return res;
    }
    
    void backtrack(int n, vector<int> nums, vector<vector<int>>& res, int start) {
        if (start == n) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < n; i++) {
            swap(nums[i], nums[start]);
            backtrack(n, nums, res, start+1);
            swap(nums[i], nums[start]);
        }
        return;
    }
};


// DFS
// 深搜，其实也可以用next permutation的方法
// 需要维护一个used数组，存哪些用过哪些没用过
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n, false);
        vector<vector<int>> res;
        vector<int> cur;
        help(cur, res, used, nums);
        return res;
    }
    
    void help(vector<int> cur, vector<vector<int>>& res, vector<bool> used, vector<int> nums) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            help(cur, res, used, nums);
            cur.pop_back();
            used[i] = false;
        }
        return;
    }
};