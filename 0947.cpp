class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> f, cnt;
        for (int i = 0; i < n; i++) {
            f.push_back(i);
            cnt.push_back(1);
            stones[i].push_back(i); // label stone with index
        }
        sort(stones.begin(), stones.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        }); // sort by x-axis
        for (int i = 0; i < n; i++) {
            if (i > 0 && stones[i-1][0] == stones[i][0]) {
                // cout << stones[i-1][2] << ' ' << stones[i][2] << ' ' << f[stones[i-1][2]] << ' ' << f[stones[i][2]] << endl;
                uni(f, cnt, stones[i-1][2], stones[i][2]);
            }
        }
        sort(stones.begin(), stones.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        }); // sort by y-axis
        for (int i = 0; i < n; i++) {
            if (i > 0 && stones[i-1][1] == stones[i][1]) {
                uni(f, cnt, stones[i-1][2], stones[i][2]);
            }
        }
        // for (int i = 0; i < n; i++) {
        //     cout << f[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << cnt[i] << ' ';
        // }
        // cout << endl;
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i == find(f, i)) {
                res += cnt[i] - 1;
            }
        }
        return res;
    }
    
    int find(vector<int>& f, int i) {
        while (i != f[i]) i = f[i];
        return i;
    }
    
    void uni(vector<int>& f, vector<int>& cnt, int x, int y) {
        int fx = find(f, x);
        int fy = find(f, y);
        if (fx != fy) {
            if (cnt[fx] < cnt[fy]) {
                f[fx] = fy;
                cnt[fy] += cnt[fx];
            } else {
                f[fy] = fx;
                cnt[fx] += cnt[fy];
            }
        }
    }
};