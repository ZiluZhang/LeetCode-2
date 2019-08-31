class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int> q;
        for (vector<int> pt: points) {
            int dis = pt[0]*pt[0] + pt[1]*pt[1];
            q.push(dis);
            if (q.size() > k) q.pop();
        }
        int threshold = q.top();
        vector<vector<int>> res;
        for (vector<int> pt: points) {
            int dis = pt[0]*pt[0] + pt[1]*pt[1];
            if (dis <= threshold) res.push_back(pt);
        }
        return res;
    }
};