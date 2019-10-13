class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<long> m;
        for (auto p : points) {
            m.insert((long)p[0] * 40000 + p[1]);
        }
        int res = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    int x1 = points[i][0], y1 = points[i][1];
                    int x2 = points[j][0], y2 = points[j][1];
                    if (m.count((long)x1*40000+y2) && m.count((long)x2*40000+y1)) {
                        res = min(abs(x1-x2)*abs(y1-y2), res);
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};