class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> m;
        unordered_set<char> used;
        for (int i = 0; i < s.length(); i++) {
            if (m.count(s[i]) && m[s[i]]!= t[i]) return false;
            if (m.count(s[i]) == 0 && used.count(t[i])) return false;
            m[s[i]] = t[i];
            used.insert(t[i]);
        }
        return true;
    }
};