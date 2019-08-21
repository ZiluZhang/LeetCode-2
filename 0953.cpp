class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> m;
        for (int i = 0; i < 26; i++) {
            m[order[i]] = 'a' + i;
        }
        int num = words.size();
        for (int i = 0; i < num; i++) {
            string tmp = "";
            for (char c: words[i]) {
                tmp += m[c];
            }
            words[i] = tmp;
        }
        for (int i = 1; i < num; i++) {
            if (words[i-1] > words[i]) {
                return false;
            }
        }
        return true;
    }
};