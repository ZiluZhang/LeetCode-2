class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        priority_queue<pair<int, int>> q; // default min heap
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (q.size() >= k) {
                if (0-it->second < q.top().first) {
                    q.pop();
                    q.push(pair<int, int>(0-it->second, it->first));
                }
            } else {
                q.push(pair<int, int>(0-it->second, it->first));
            }
            
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};