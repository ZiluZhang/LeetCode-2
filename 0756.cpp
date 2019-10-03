class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> m;
        for (auto a: allowed) {
            m[a.substr(0, 2)].insert(a[2]);
        }
        return helper(bottom, "", m);
    }
    
    bool helper(string cur, string top, unordered_map<string, unordered_set<char>>& m) {
        if (cur.size() == 2 && top.size() == 1) return true;
        if (cur.size() == top.size() + 1) return helper(top, "", m);
        int pos = top.size();
        string base = cur.substr(pos, 2);
        if (m.count(base)) {
            auto s = m[base];
            for (auto c: s) {
                if (helper(cur, top + c, m))
                    return true;
            }
            return false;
        }
        return false;
    }
};