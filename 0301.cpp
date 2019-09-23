class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q{{s}};
        unordered_set<string> visited{{s}};
        bool found = false;
        while (!q.empty()) {
            if (found) break;
            for (int k = q.size(); k > 0; k--) {
                string cur = q.front(); q.pop();
                if (checkValid(cur)) {
                    res.push_back(cur);
                    found = true;
                }
                if (found) continue;
                for (int i = 0; i < cur.size(); i++) {
                    if (cur[i] != '(' && cur[i] != ')') continue;
                    string tmp = cur.substr(0, i) + cur.substr(i+1);
                    if (!visited.count(tmp)) {
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                }
            }
        }
        return res;
    }
    
    bool checkValid(string s) {
        int cnt = 0;
        for (char c: s) {
            if (c == '(') cnt++;
            else if (c == ')') cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};