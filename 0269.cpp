class Solution {
public:
    bool checkAll(unordered_map<char, int>& indegree) {
        for (char a = 'a'; a <= 'z'; a++)
            if (indegree[a]) return false;
        return true;
    }
    
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> paths;
        unordered_map<char, int> indegree;
        unordered_set<char> chars;
        for (string w: words) {
            for (char c: w)
                chars.insert(c);
        }
        for (int i = 1; i < words.size(); i++) {
            string w1 = words[i-1];
            string w2 = words[i];
            for (int j = 0; j < w1.size() && j < w2.size(); j++) {
                if (w1[j] != w2[j]) {
                    if (paths[w1[j]].count(w2[j]) == 0) {
                        paths[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break; // only check first different character
                }
            }
        }
        queue<char> q;
        for (char c: chars) {
            if (indegree[c] == 0) q.push(c);
        }
        string res = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            unordered_set<char> s = paths[c];
            for (auto it = s.begin(); it != s.end(); it++) {
                indegree[(*it)]--;
                if (indegree[(*it)] == 0) q.push((*it));
            }
        }
        if (!checkAll(indegree)) return "";
        return res;
    }
};