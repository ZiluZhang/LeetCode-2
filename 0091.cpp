class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        vector<int> dp(len, 0);
        dp[0] = s[0]=='0' ? 0 : 1;
        for (int i = 1; i < len; i++) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    dp[i] = i-2>=0 ? dp[i-2] : 1;
                } else {
                    return 0;
                }
            }
            int tmp = stoi(s.substr(i-1, 2));
            if (tmp < 10 || tmp > 26) {
                dp[i] = dp[i-1];
            } else if ('1' <= s[i] && s[i] <= '9') {
                dp[i] = i-2>=0 ? dp[i-1] + dp[i-2] : dp[i-1] + 1;
            } else {
                dp[i] = i-2>=0 ? dp[i-2] : 1;
            }
        }
        return dp[len-1];
    }
};