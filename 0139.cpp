class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        queue<int> q;
        q.push(0);
        int len = s.length();
        vector<bool> visited(len, false);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (visited[cur]) continue;
            for (int i = cur; i < len; i++) {
                string tmp = s.substr(cur, i-cur+1);
                if (words.count(tmp)) {
                    if (i == len-1) return true;
                    q.push(i+1);
                }
            }
            visited[cur] = true;
        }
        return false;
    }
};