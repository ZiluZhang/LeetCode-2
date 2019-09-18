class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> wordDict(words.begin(), words.end());
        vector<string> res;
        for (string word: words) {
            if (word.length() == 0) continue;
            if (checkWordBreak(word, wordDict)) {
                res.push_back(word);
            }
        }
        return res;
    }
    
    bool checkWordBreak(string s, unordered_set<string>& wordDict) {
        int len = s.length();
        queue<int> q;
        vector<bool> visited(len, false);
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur]) continue;
            for (int i = cur; i < len; i++) {
                string tmp = s.substr(cur, i-cur+1);
                if (tmp == s) continue;
                if (wordDict.count(tmp)) {
                    if (i == len-1) return true;
                    q.push(i+1);
                }
            }
            visited[cur] = true;
        }
        return false;
    }
};