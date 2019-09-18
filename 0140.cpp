class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_map<string, vector<string>> m;
        res = helper(s, wordDict, m);
        
        return res;
    }
    
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        if (m.count(s)) return m[s];
        if (s.size() == 0) return {""};
        vector<string> tmp;
        for (string word: wordDict) {
            if (s.substr(0, word.size()) == word) {
                vector<string> rem = helper(s.substr(word.size()), wordDict, m);
                for (string str: rem) {
                    if (str.length() == 0) {
                        tmp.push_back(word);
                    } else {
                        tmp.push_back(word + ' ' + str);
                    }
                }
            }
        }
        m[s] = tmp;
        return tmp;
    }
};