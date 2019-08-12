class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt = 0;
        int start = 0;
        int end = -1;
        int len = S.length();
        string res = "";
        for (int i = 0; i < len; i++) {
            if (S[i] == '(') {
                cnt++;
            } else if (S[i] == ')') {
                cnt--;
            }
            if (cnt == 0) {
                end = i;
                if (start != end) {
                    res += S.substr(start+1, end-start-1);
                }
                start = end+1;
            }
        }
        return res;
    }
};