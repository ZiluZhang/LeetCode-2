class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int res = nums.size();
        int degree = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
            degree = max(degree, m[nums[i]]);
            if (left.find(nums[i]) == left.end()) left[nums[i]] = i;
            right[nums[i]] = i;
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == degree) {
                res = min(res, right[it->first] - left[it->first]+1);
            }
        }
        return res;
    }
};