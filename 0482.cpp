class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = "";
        int cnt = 0;
        for (int i = S.length()-1; i >= 0; i--) {
            if (S[i] == '-') continue;
            res += (char)toupper(S[i]);
            cnt++;
            if (cnt == K && i > 0) {
                cnt = 0;
                res += "-";
            }
        }
        if (res.back() == '-') res.pop_back();
        return string(res.rbegin(), res.rend());
    }
};