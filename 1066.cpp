class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int res = INT_MAX;
        int m = workers.size();
        int n = bikes.size();
        vector<vector<int>> dis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = getDis(workers, bikes, i, j);
                dis[i][j] = tmp;
            }
        }
        vector<int> bikeIdx(n, 0);
        for (int i = 0; i < n; i++) bikeIdx[i] = i;
        helper(bikeIdx, dis, 0, 0, 0, res);
        return res;
    }
    
    void helper(vector<int>& bikeIdx, vector<vector<int>>& dis, int i, int j, int cur, int& res) {
        if (i == dis.size()) {
            res = min(res, cur);
            return;
        }
        if (cur >= res) return;
        for (int k = j; k < bikeIdx.size(); k++) {
            swap(bikeIdx[j], bikeIdx[k]);
            helper(bikeIdx, dis, i+1, j+1, cur+dis[i][bikeIdx[j]], res);
            swap(bikeIdx[j], bikeIdx[k]);
        }
        return;
    }
    
    int getDis(vector<vector<int>>& workers, vector<vector<int>>& bikes, int i, int j) {
        return abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
    }
};