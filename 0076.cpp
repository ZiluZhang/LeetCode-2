class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length()) return "";
        int min_len = INT_MAX;
        string res = "";
        vector<int> cnt(288, 0);
        for (char c: t) cnt[c]++;
        int i = 0, j = 0;
        int len1 = s.length(), len2 = t.length();
        vector<int> tmp(288, 0);
        tmp[s[0]]++;
        while (i + len2 <= len1 && j < len1) {
            if (j-i+1 < len2) {
                tmp[s[++j]]++;
                continue;
            }
            if (!checkSubstr(cnt, tmp)) {
                j++;
                if (j < len1) tmp[s[j]]++;
            } else {
                if (j-i+1 < min_len) {
                    min_len = j-i+1;
                    res = s.substr(i, j-i+1);
                }
                tmp[s[i++]]--;
            }
        }
        return res;
    }
    
    bool checkSubstr(vector<int>& a1, vector<int>& a2) {
        for (int i = 0; i < 288; i++) {
            if (a2[i] < a1[i]) return false;
        }
        return true;
    }
};