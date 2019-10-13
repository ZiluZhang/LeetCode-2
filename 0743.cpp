class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto t : times) {
            graph[t[0]].push_back({t[1], t[2]});
        }
        unordered_map<int, int> dis;
        for (int i = 1; i <= N; i++) {
            dis[i] = INT_MAX;
        }
        dis[K] = 0;
        vector<bool> visited(N+1, false);
        while (true) {
            int curNode = -1;
            int curDis = INT_MAX;
            for (int i = 1; i <= N; i++) {
                if (!visited[i] && dis[i] < curDis) {
                    curDis = dis[i];
                    curNode = i;
                }
            }
            if (curNode < 0) break;
            visited[curNode] = true;
            if (graph.count(curNode)) {
                for (auto e : graph[curNode]) {
                    dis[e.first] = min(dis[e.first], dis[curNode] + e.second);
                }
            }
        }
        
        int res = 0;
        for (int i = 1; i <= N; i++) {
            res = max(res, dis[i]);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};