class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int e = flights.size();
        unordered_map<int, vector<vector<int>>> m;
        unordered_set<int> visited{{src}};
        for (auto f: flights) {
            m[f[0]].push_back({f[1], f[2]});
        }
        int res = INT_MAX;
        helper(m, visited, src, 0, dst, K, res);
        return res == INT_MAX ? -1 : res;
    }
    
    void helper(unordered_map<int, vector<vector<int>>>& m, unordered_set<int>& visited, int curIdx, int curCost, int dst, int K, int& res) {
        if (curIdx == dst) {
            res = curCost;
            return;
        }
        if (K < 0) return;
        for (auto v : m[curIdx]) {
            if (visited.count(v[0]) || v[1] + curCost > res) continue;
            visited.insert(v[0]);
            helper(m, visited, v[0], curCost + v[1], dst, K-1, res);
            visited.erase(v[0]);
        }
        return;
    }
};