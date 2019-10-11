class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int m = queries.size();
        int n = words.size();
        vector<int> f1(m, 0);
        vector<int> f2(n, 0);
        for (int i = 0; i < m; i++) f1[i] = getF(queries[i]);
        for (int j = 0; j < n; j++) f2[j] = getF(words[j]);
        vector<int> res;
        for (int k : f1) {
            int cnt = 0;
            for (int i : f2) {
                if (i > k) cnt++;
            }
            res.push_back(cnt);
        }
        return res;
    }
    
    int getF(string& s) {
        vector<int> cnt(26, 0);
        for (char c: s) {
            cnt[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) return cnt[i];
        }
        return 0;
    }
};