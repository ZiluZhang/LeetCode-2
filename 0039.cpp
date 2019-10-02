class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        helper(candidates, target, 0, 0, {}, res);
        return res;
    }
    
    void helper(vector<int>& candidates, int target, int s, int curSum, vector<int> cur, vector<vector<int>>& res) {
        if (curSum == target) {
            res.push_back(cur);
            return;
        }
        for (int i = s; i < candidates.size(); i++) {
            if (curSum + candidates[i] > target) continue;
            curSum += candidates[i];
            cur.push_back(candidates[i]);
            helper(candidates, target, i, curSum, cur, res);
            cur.pop_back();
            curSum -= candidates[i];
        }
        
    }
};