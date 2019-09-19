class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && q.top().second <= i-k) q.pop();
            q.push({nums[i], i});
            if (i >= k-1) res.push_back(q.top().first);
        }
        return res;
    }
};