class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.length();
        int n = t.length();
        if (abs(m-n) >= 2) return false;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                if (m == n) return s.substr(i+1) == t.substr(j+1);
                else if (m == n-1) return s.substr(i) == t.substr(j+1);
                else return s.substr(i+1) == t.substr(j);
            }
        }
        return abs(m-n) == 1;
    }
};