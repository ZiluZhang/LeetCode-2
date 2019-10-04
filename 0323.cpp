class Solution {
public:
    int find(vector<int>& father, int i) {
        while (father[i] != i) i = father[i];
        return i;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> father(n, 0);
        for (int i = 0; i < n; i++) father[i] = i;
        for (auto e: edges) {
            int f1 = find(father, e[0]);
            int f2 = find(father, e[1]);
            if (f1 != f2) {
                father[f1] = f2;
            }
        }
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(find(father, i));
        }
        return s.size();
    }
};