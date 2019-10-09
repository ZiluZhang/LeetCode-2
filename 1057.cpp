class my_pair {
public:
    int dis;
    int worker;
    int bike;
    my_pair(int d, int w, int b) {
        dis = d;
        worker = w;
        bike = b;
    }
    bool operator<(const my_pair & b) const {
        if (dis != b.dis) return dis > b.dis;
        if (worker != b.worker) return worker > b.worker;
        return bike > b.bike;
    }
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<my_pair> q;
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                int dis = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                my_pair tmp(dis, i, j);
                q.push(tmp);
            }
        }
        // vector<bool> visited(workers.size(), false);
        vector<int> res(workers.size(), -1);
        vector<bool> used(bikes.size(), false);
        while (!q.empty()) {
            auto cur = q.top(); q.pop();
            // cout << cur[0] << ' ' << cur[1] << ' ' << cur[2] << endl;
            if (res[cur.worker] != -1 || used[cur.bike]) continue;
            res[cur.worker] = cur.bike;
            used[cur.bike] = true;
        }
        return res;
    }
};