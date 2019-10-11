class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        int n = str1.length();
        unordered_map<char, char> m{{}};
        unordered_set<char> used;
        for (int i = 0; i < n; i++) {
            if (m.count(str1[i]) && m[str1[i]] != str2[i])
                return false;
            m[str1[i]] = str2[i];
            used.insert(str2[i]);
        }
        return used.size() < 26;
    }
};