class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int k = 2; k <= n; k++) {
            int len = s.length();
            string tmp = "";
            int i = 0;
            while (i < len) {
                char cur = s[i];
                int cnt = 1;
                while (i + 1 < len && s[i] == s[i+1]) {
                    i++;
                    cnt++;
                }
                tmp += to_string(cnt) + cur;
                i++;
            }
            s = tmp;
        }
        return s;
    }
};