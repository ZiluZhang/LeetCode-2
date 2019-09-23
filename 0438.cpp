class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.length() == 0 || p.length() == 0 || s.length() < p.length()) return {};
        int len = p.length();
        vector<int> cnt(26, 0);
        for (char c: p) cnt[c-'a']++;
        vector<int> cur(26, 0);
        for (int k = 0; k < len; k++) cur[s[k]-'a']++;
        int i = 0, j = len-1;
        vector<int> res;
        while (j < s.length()) {
            if (check(cnt, cur)) res.push_back(i);
            cur[s[i++]-'a']--;
            j++;
            if (j < s.length()) cur[s[j]-'a']++;
        }
        return res;
    }
    
    bool check(vector<int>& v1, vector<int>& v2) {
        for (int i = 0; i < 26; i++) {
            if (v1[i] != v2[i]) return false;
        }
        return true;
    }
};