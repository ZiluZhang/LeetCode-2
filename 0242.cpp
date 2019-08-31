class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c-'a']++;
        }
        vector<int> cnt2(26, 0);
        for (char c: t) {
            cnt2[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != cnt2[i]) return false;
        }
        return true;
    }
};