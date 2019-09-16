class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> ban;
        for (string s: banned) {
            ban.insert(s);
        }
        int maxCnt = 0;
        string res;
        unordered_map<string, int> cnt;
        for (int i = 0; i < paragraph.length(); i++) {
            if (!isupper(paragraph[i]) && !islower(paragraph[i])) {
                continue;
            }
            int start = i;
            string cur = "";
            while (i < paragraph.length() && (isupper(paragraph[i]) || islower(paragraph[i]))) {
                cur += tolower(paragraph[i]);
                i++;
            }
            if (ban.find(cur) == ban.end()) {
                cnt[cur]++;
                if (cnt[cur] > maxCnt) {
                    maxCnt = cnt[cur];
                    res = cur;
                }
            }
        }
        return res;
    }
};