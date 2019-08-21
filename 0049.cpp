class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string str: strs) {
            string encoded = encodeStr(str);
            if (map.count(encoded)) {
                map[encoded].push_back(str);
            } else {
                vector<string> tmp(1, str);
                map[encoded] = tmp;
            }
        }
        vector<vector<string>> res;
        for (auto it = map.begin(); it != map.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
    
    string encodeStr(string str) {
        vector<int> cnt(26, 0);
        for (char c: str) {
            cnt[c-'a']++;
        }
        string res = "";
        for (int c: cnt) {
            res += to_string(c);
        }
        return res;
    }
};