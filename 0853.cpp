class comp {
    public:
    bool operator()(pair<int, double>& a, pair<int, double>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        int n = position.size();
        if (n == 1) return 1;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], (target-position[i]) * 1.0 / speed[i]});
        }
        sort(cars.begin(), cars.end(), comp());
        // for (int i = 0; i < n; i++) {
        //     cout << cars[i].first << ' ' << cars[i].second << endl;
        // }
        int res = n;
        for (int i = 1; i < n; i++) {
            if (cars[i].second <= cars[i-1].second) {
                res--;
                cars[i].second = cars[i-1].second;
            }
        }
        return res;
    }
};