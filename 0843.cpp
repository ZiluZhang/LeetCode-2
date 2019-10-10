/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int n = wordlist.size();
        vector<vector<int>> sim(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            sim[i][i] = 6;
            for (int j = i+1; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < 6; k++) {
                    if (wordlist[i][k] == wordlist[j][k]) {
                        cnt++;
                    }
                }
                sim[i][j] = cnt;
                sim[j][i] = cnt;
            }
        }
        
        vector<int> possible;
        unordered_set<int> used;
        // Master master;
        for (int i = 0; i < n; i++) {
            possible.push_back(i);
        }
        
        while (!possible.empty()) {
            int idx = getGuess(possible, used, sim);
            int cnt = master.guess(wordlist[idx]);
            if (cnt == 6) return;
            vector<int> cur;
            for (auto k : possible) {
                if (sim[idx][k] == cnt) {
                    cur.push_back(k);
                }
            }
            possible = cur;
            used.insert(idx);
        }
        return;
    }
    
    
    int getGuess(vector<int>& possible, unordered_set<int>& used, vector<vector<int>>& sim) {
        if (possible.size() <= 2) return possible[0];
        int n = sim.size();
        int res = -1;
        int maxSize = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!used.count(i)) {
                vector<int> cnt(7, 0);
                for (auto j : possible) {
                    if (j != i) {
                        cnt[sim[i][j]]++;
                    }
                }
                int curMax = -1;
                for (int k = 0; k <= 6; k++) {
                    curMax = max(curMax, cnt[k]);
                }
                if (curMax < maxSize) {
                    maxSize = curMax;
                    res = i;
                }
            }
        }
        return res;
    }
};