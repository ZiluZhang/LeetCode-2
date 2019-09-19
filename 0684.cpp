class Solution {
public:
    
    int find(vector<int>& f, int i) {
        while (f[i] != i) {
            i = f[i];
        }
        return f[i];
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> f(1001, 0);
        for (int i = 0; i < 1001; i++) f[i] = i;
        for (auto e: edges) {
            int x = find(f, e[0]), y = find(f, e[1]);
            if (find(f, e[0]) == find(f, e[1])) return e;
            f[x] = y;
        }
        return {};
    }
};