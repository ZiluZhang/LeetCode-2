class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> s{{0}};
        queue<int> q{{0}};
        for (auto e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto t : g[cur]) {
                if (s.find(t) != s.end()) {
                    // cout << t;
                    return false;
                }
                s.insert(t);
                g[t].erase(cur);
                q.push(t);
            } 
        }
        // cout << s.size();
        return s.size() == n;
    }
};