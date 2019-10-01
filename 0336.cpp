class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        set<int> s;
        for (int i = 0; i < words.size(); i++) {
            m[words[i]] = i;
            s.insert(words[i].length());
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            string cur = words[i];
            reverse(cur.begin(), cur.end());
            int len = cur.length();
            if (m.count(cur) && m[cur] != i) {
                res.push_back({i, m[cur]});
            }
            auto a = s.find(len);
            for (auto it = s.begin(); it != a; it++) {
                int d = *it;
                if (isPalindrome(cur, 0, len-1-d) && m.count(cur.substr(len-d))) {
                    res.push_back({i, m[cur.substr(len-d)]});
                }
                if (isPalindrome(cur, d, len-1) && m.count(cur.substr(0, d))) {
                    res.push_back({m[cur.substr(0, d)], i});
                }
            }
        }
        return res;
    }
    
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};