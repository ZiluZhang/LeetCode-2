class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string & s1, string & s2) {
            if (s1.length() == s2.length()) return s1 < s2;
            return s1.length() > s2.length();
        });
        for (auto str : d) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) i++;
            }
            if (i == str.size()) return str;
        }
        return "";
    }
};