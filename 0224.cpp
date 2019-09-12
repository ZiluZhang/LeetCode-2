class Solution {
public:
    int calculate(string str) {
        stack<int> s;
        int len = str.length();
        int sign = 1;
        int i = 0;
        int res = 0;
        while (i < len) {
            // cout << i << endl;
            char c = str[i];
            if (c == ' ') {
                i++;
                continue;
            }else if ('0' <= c && c <= '9') {
                int n = 0;
                while (i < len && '0' <= str[i] && str[i] <= '9') {
                    n = n * 10 + (str[i] - '0');
                    i++;
                }
                res += sign * n;
                // cout << res << endl;
                i--;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                s.push(res);
                s.push(sign);
                sign = 1;
                res = 0;
            } else if (c == ')') {
                int tmpsign = s.top();
                s.pop();
                int tmpres = s.top();
                s.pop();
                res = res * tmpsign + tmpres;
            }
            i++;
        }
        return res;
    }
};